from datetime import datetime
from LLM_Util.LLm import extract_score
from LLM_Util.LLm_class import QAClass
from writer import write
import os
from LLM_Util.exist_coverage import exist
from LLM_Util.LLm import extract_imp_score,extract_imp_score_new_prompt
import glob
import time

THRESHOLD = 7

def LLM_candidate(candidate, candidate_set_with_line_number, context):
    cand = [c for c in candidate if c != ""]
    if len(cand) == 1:
        if cand[0] == " }" or cand[0] == " {" or cand[0] == "}" or cand[0] == "{":
            return 0
    

    # Ensure directories exist
    os.makedirs("../LLM_Util/cands/removed_code", exist_ok=True)
    os.makedirs("../LLM_Util/cands/context", exist_ok=True)
    os.makedirs("../LLM_Util/cands/pretext_code", exist_ok=True)
    os.makedirs("../LLM_Util/cands/llm_response", exist_ok=True)

    now = datetime.now()
    formatted_time = now.strftime("%H-%M-%S-%f")[:-3]
    outfile = "../LLM_Util/cands/removed_code/removed_code" + "_time_"+  str(formatted_time)+ ".blade.c"
    write(candidate, outfile)
    clang_format_command = f"clang-format -i {outfile}"
    os.system(clang_format_command)

    cand_linenum = "../LLM_Util/cands/context/context" + "_time_"+  str(formatted_time)+ ".blade.c"
    write(candidate_set_with_line_number, cand_linenum)

    # clean empty lines in context for query to DB
    first_non_empty_index = next((i for i, x in enumerate(context) if x), len(context))
    last_non_empty_index = next((i for i, x in enumerate(reversed(context)) if x), len(context))
    context_clean = context[first_non_empty_index:len(context) - last_non_empty_index]

    # write pretext context to file 
    context_file = "../LLM_Util/cands/pretext_code/context" + "_time_"+ str(formatted_time)+ ".blade.c"
    write(context_clean, context_file)

    # write llm response to file 
    llm_file = "../LLM_Util/cands/llm_response/llm" + "_time_"+ str(formatted_time)+ ".blade.c.txt"

    string_to_keep = "double custom_log(double num) {"

    return 0
    qa = QAClass() 
    try:
        # time.sleep(10)
        query=""
        llm_response=""
        with open(outfile, 'r') as file:
            query = file.read()
        
        with open(context_file, 'r') as file:
            context_clean = file.read()

        exist_in_coverage = exist(outfile)

        # get llm response from cache if cand set is repeating
        llm_cache = check_previous_responses(cand_linenum)

        # query llm only if cache is empty
        if llm_cache == None:
            if (exist_in_coverage):
                llm_response = qa.invoke(query, 'security', context_clean)
            else:
                llm_response = qa.invoke(query, 'generality', context_clean)
        else:
            print("Using Cached LLM Response")
            llm_response = llm_cache
        
        # write the llm response to a file for manual verification
        print("###\nResponse: ", llm_response)
        if llm_response != "":
            with open(llm_file, 'w') as file:
                file.write(llm_response)
        else:
            with open(llm_file, 'w') as file:
                file.write("LLM failed to generate response")

        score = extract_imp_score_new_prompt(llm_response)
        # print("Candidate set: ", candidate, "\nScore: ", score)
        if score == None:
            return 0
        return score
    except Exception as e:
        print(str(e))
    return 0 # in case LLM fails, leave the decision to tool


# util to check if query already existed before, fetch llm response from cache
def check_previous_responses(query_file_name):
    llm_response = None
    # print("directory:",os.getcwd())
    try:
        # print("Query file name: ", query_file_name)
        all_files = glob.glob('../LLM_Util/cands/context_*.c')
        # print("Files read,",len(all_files))
        with open(query_file_name, 'r') as file:
            query_file_data = file.read()

        for each in all_files:
            with open(each, 'r') as file:
                current_file_data = file.read()
            
            if each != query_file_name:
                if current_file_data == query_file_data:
                    # print("DUP FOUND")
                    # read the corresponding llm response
                    splits = (each.split("/")[-1]).split("_")
                    splits.pop(0)
                    llm_response_filename = "llm_" + "_".join(splits) + ".txt"
                    # print("reading:",llm_response_filename)
                    with open("../LLM_Util/cands/llm_response/" + llm_response_filename, 'r') as file:
                        llm_response = file.read()
                    # print(llm_response)
                    return llm_response
    except:
        return None
    
    return llm_response
                    