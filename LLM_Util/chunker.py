from __future__ import annotations
import re
from tree_sitter_languages import get_language, get_parser
from dataclasses import dataclass
import requests
from tree_sitter import Node, Tree
from dataclasses import field

language = get_language("c")
parser = get_parser("c")

@dataclass
class Span:
    # Represents a slice of a string
    start: int = 0
    end: int = 0

    def __post_init__(self):
        # If end is None, set it to start
        if self.end is None:
            self.end = self.start

    def extract(self, s: str) -> str:
        # Grab the corresponding substring of string s by bytes
        return s[self.start : self.end]

    def extract_lines(self, s: str) -> str:
        # Grab the corresponding substring of string s by lines
        return "\n".join(s.splitlines()[self.start : self.end])

    def __add__(self, other: Span | int) -> Span:
        # e.g. Span(1, 2) + Span(2, 4) = Span(1, 4) (concatenation)
        # There are no safety checks: Span(a, b) + Span(c, d) = Span(a, d)
        # and there are no requirements for b = c.
        if isinstance(other, int):
            return Span(self.start + other, self.end + other)
        elif isinstance(other, Span):
            return Span(self.start, other.end)
        else:
            raise NotImplementedError()

    def __len__(self) -> int:
        # i.e. Span(a, b) = b - a
        return self.end - self.start

def non_whitespace_len(s: str) -> int:  # new len function
    return len(re.sub("\s", "", s))

def get_line_number(index: int, source_code: str) -> int:
    total_chars = 0
    for line_number, line in enumerate(source_code.splitlines(keepends=True), start=1):
        total_chars += len(line)
        if total_chars > index:
            return line_number - 1
    return line_number


def chunker(
    tree: Tree,
    source_code: bytes,
    MAX_CHARS=512 * 3,
    coalesce=75,  # Any chunk less than 50 characters long gets coalesced with the next chunk
) -> list[Span]:

    # 1. Recursively form chunks based on the last post (https://docs.sweep.dev/blogs/chunking-2m-files)
    def chunk_node(node: Node) -> list[Span]:
        chunks: list[Span] = []
        current_chunk: Span = Span(node.start_byte, node.start_byte)
        node_children = node.children
        for child in node_children:
            if child.end_byte - child.start_byte > MAX_CHARS:
                chunks.append(current_chunk)
                current_chunk = Span(child.end_byte, child.end_byte)
                chunks.extend(chunk_node(child))
            elif child.end_byte - child.start_byte + len(current_chunk) > MAX_CHARS:
                chunks.append(current_chunk)
                current_chunk = Span(child.start_byte, child.end_byte)
            else:
                current_chunk += Span(child.start_byte, child.end_byte)
        chunks.append(current_chunk)
        return chunks

    chunks = chunk_node(tree.root_node)

    # 2. Filling in the gaps
    for prev, curr in zip(chunks[:-1], chunks[1:]):
        prev.end = curr.start
    curr.start = tree.root_node.end_byte

    # # 3. Combining small chunks with bigger ones
    # new_chunks = []
    # current_chunk = Span(0, 0)
    # for chunk in chunks:
    #     current_chunk += chunk
    #     if non_whitespace_len(
    #         current_chunk.extract(source_code)
    #     ) > coalesce and "\n" in current_chunk.extract(source_code):
    #         new_chunks.append(current_chunk)
    #         current_chunk = Span(chunk.end, chunk.end)
    # if len(current_chunk) > 0:
    #     new_chunks.append(current_chunk)

    ######## Modified Step.3 Below ########

    new_chunks = []
    current_chunk = Span(0, 0)

    for chunk in chunks:
        # Extract the chunk's text from the source code
        chunk_text = chunk.extract(source_code)
        
        # Check if the chunk starts with '}'
        if chunk_text.strip().startswith('return') or chunk_text.strip() == '}' or chunk_text.strip() == '};':
            # If it does, append the current chunk to new_chunks
            # and then add the new chunk to the previous chunk
            if len(new_chunks) > 0:
                previous_chunk = new_chunks.pop()
                previous_chunk += chunk
                new_chunks.append(previous_chunk)
                # print("\n===========\n",previous_chunk.extract(source_code))
            else:
                # If no previous chunk exists, just add it to the current_chunk
                current_chunk += chunk
        else:
            # Regular processing: append the chunk to the current chunk
            current_chunk += chunk
            
            # If the current_chunk is large enough or contains a newline
            if (non_whitespace_len(current_chunk.extract(source_code)) > coalesce) and "\n" in current_chunk.extract(source_code):
                new_chunks.append(current_chunk)
                current_chunk = Span(chunk.end, chunk.end)

    # Add any remaining current_chunk to new_chunks
    if len(current_chunk) > 0:
        new_chunks.append(current_chunk)

    ######## Modified Step.3 Above ########


    # 4. Changing line numbers
    line_chunks = [
        Span(
            get_line_number(chunk.start, source_code),
            get_line_number(chunk.end, source_code),
        )
        for chunk in new_chunks
    ]

    # 5. Eliminating empty chunks
    line_chunks = [chunk for chunk in line_chunks if len(chunk) > 0]

    return line_chunks


def get_code_chunks(python_code: str) -> list[str]:
    tree = parser.parse(python_code.encode("utf-8"))
    chunks = chunker(tree, python_code)
    return [chunk.extract_lines(python_code) for chunk in chunks]

# # Example usage
# with open("../src/original.txt") as f:
#     python_code = f.read()
#     print(type(python_code))



# chunks = get_code_chunks(python_code)
# for chunk in chunks:
#     print(chunk + "\n\n====================\n\n")