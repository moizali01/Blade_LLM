import os

def analyze_code(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    first_line_of_code = None
    last_line_of_code = None

    for index, line in enumerate(lines):
        if line.strip():  # Check if the line is not empty
            if first_line_of_code is None:
                first_line_of_code = index + 1  # Line numbers start from 1

            last_line_of_code = index + 1

    return first_line_of_code, last_line_of_code



def get_llm_class(file_name):
    with open(file_name, "r") as f:
        response = f.read()

    class_extracted = extract_imp_score_new_prompt(response)

    return class_extracted
    

def extract_imp_score_new_prompt(text): 

    # Convert the text to lowercase
    lower_text = text.lower()
    target = "final verdict"

    # Find the position of "importance score"
    start_index = lower_text.find(target)
    if start_index == -1:
        return None  # "Importance Score" not found

    # Move the start index to the end of "importance score"
    start_index += len(target)

    # Find the next newline character after "importance score"
    end_index = text.find('\n', start_index)
    if end_index == -1:
        end_index = len(text)  # if no newline, go to the end of the text

    # Extract the substring between "importance score" and the newline
    substring = text[start_index:end_index]

    # Find the number in the substring
    import re
    match = re.search(r'\b([0-9]|[1-9][0-9]|100)\b', substring)
    if match:
        assigned_class = int(match.group(0))
        # removal class
        if assigned_class < 3:
            return 1
        else:
            return 9
    else:
        return None  # No number found
    


def check_if_commented_out(file_path, start_line, end_line):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    for index, line in enumerate(lines):
        if index >= start_line and index <= end_line:
            if "//" in line:
                # print("Code is commented out")
                return True

    return False


def get_benchmark_length(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    return len(lines)

def compare_benchmark(debloated_file, benchmark_file):
    # os.system(f"astyle -j -A4 {debloated_file}")
    # os.system(f"astyle -j -A4 {benchmark_file}")
    
    # debloated
    merged_files = []
    
    false_retention = 0
    false_removal = 0

    false_retention_files = []
    false_removal_files = []

    # get array of length of number of lines in benchmark
    lines_queried_from_original = [False for i in range(0, get_benchmark_length(benchmark_file))]

    lines_removed_by_llm = [False for i in range(0, get_benchmark_length(benchmark_file))]

    lines_removed_by_benchmark = [False for i in range(0, get_benchmark_length(benchmark_file))]

    # load benchmark, mark removed lines as True
    with open(benchmark_file, 'r') as file:
        benchmark_lines = file.readlines()
    for i,each in enumerate(benchmark_lines):
        if "//" in each:
            lines_removed_by_benchmark[i] = True 

    # read all file names from cands/removed_code
    for root, dirs, files in os.walk("cands/context"):
        for file in files:
            merged_files.append(file)
    
    for each in merged_files:

        timestamp = (each.split("_")[-1])[:-8]
        # print(f"timestamp: {timestamp}")
        # read cand set 

        llm_class = get_llm_class(f"cands/merged_responses/merged_time_{timestamp}.blade.c.txt")

        # print(f"LLM Class: {llm_class}")

        # with open(f"cands/context/context_time_{timestamp}.blade.c", "r") as f:
        #     context = f.readlines() 
        start_code, end_code = analyze_code(f"cands/context/context_time_{timestamp}.blade.c")


        # mark Lines queried as cand sets
        for i in range(start_code, end_code):
                lines_queried_from_original[i] = True


        # mark removed lines by LLM
        for i in range(start_code, end_code):
            if llm_class == 1:
                lines_removed_by_llm[i] = True

        # check if the code is commented out in the benchmark file
        not_in_benchmark = check_if_commented_out(benchmark_file, start_code, end_code)

        # code is not in benchmark but in debloated (Bloat)
        if not_in_benchmark and llm_class == 9:
            false_retention += 1
            false_retention_files.append(f"cands/merged_responses/merged_time_{timestamp}.blade.c.txt")
        # llm removed but present in benchmark  (Extra removal)
        elif not not_in_benchmark and llm_class == 1:
            false_removal += 1
            false_removal_files.append(f"cands/merged_responses/merged_time_{timestamp}.blade.c.txt")


        # print(len(context))
    print(f"Total Cands: {len(merged_files)}")

    # make new results folder and save the false retention and false removal files
    os.makedirs("results", exist_ok=True)
    os.makedirs("results/false_retention", exist_ok=True)
    os.makedirs("results/false_removal", exist_ok=True)



    for each in false_retention_files:
        os.system(f"cp {each} results/false_retention")

    for each in false_removal_files:
        os.system(f"cp {each} results/false_removal")


    print("Lines Queried as Cand.Sets: ", sum(lines_queried_from_original))
    print("Lines Removed by LLM: ", sum(lines_removed_by_llm))
    print("Lines Removed by Benchmark: ", sum(lines_removed_by_benchmark))

    print("Lines Removed By Benchmark and LLM: ", sum([a and b for a, b in zip(lines_removed_by_benchmark, lines_removed_by_llm)]))

    return false_retention, false_removal
# compare_benchmark("debloated.c", "benchmark.c")


os.system("cd cands/context; fdupes -r -dN .")
bloat_causer, func_losser = compare_benchmark("mkdir-multiagent.c", "benchmark.c")

print(f"False Retention: {bloat_causer}")
print(f"False Removal: {func_losser}")
os.system("rm -rf *.orig")


