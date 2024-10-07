import re

def remove_comments(input_file, output_file):
    # Read the content of the file
    with open(input_file, 'r') as f:
        content = f.read()
    
    # Remove multi-line comments first
    content = re.sub(r'/\*[\s\S]*?\*/', '', content)
    
    # Remove single-line comments
    content = re.sub(r'//.*$', '', content, flags=re.MULTILINE)
    
    # Remove empty lines that might have been left after removing comments
    content = '\n'.join(line for line in content.splitlines() if line.strip())
    
    # Write the cleaned content to the output file
    with open(output_file, 'w') as f:
        f.write(content)

def main():
    try:
        input_file = input("Enter the path to the input .c file: ")
        if not input_file.endswith('.c'):
            raise ValueError("Input file must be a .c file")
            
        output_file = input_file[:-2] + '_no_comments.c'
        
        remove_comments(input_file, output_file)
        print(f"Comments removed successfully. Output saved to: {output_file}")
        
    except FileNotFoundError:
        print("Error: Input file not found")
    except ValueError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()