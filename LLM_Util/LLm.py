# Import libraries

import langchain
import os
import glob
import re
import warnings


# Setting up environment variables 
# Replace values with your azure subscription keys and deployed model information
os.environ["OPENAI_API_TYPE"] = ""
os.environ["OPENAI_API_VERSION"] = ""
os.environ["OPENAI_API_BASE"] = ""
os.environ["OPENAI_API_KEY"] = ""


def extract_score(text):    
    # Define the regular expression pattern to match the importance score
    pattern = r'(?i)importance\s*score\s*:\s*(\d+)'

    # Find and extract the importance scores from each string
    try:
        matches = re.findall(pattern, text)
        if matches:
            return int(matches[0])
    except:
        return 0

def extract_imp_score(text):    
    # Convert the text to lowercase
    lower_text = text.lower()
    target = "importance score"

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
        return int(match.group(0))
    else:
        return None  # No number found

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
        if assigned_class == 1 or assigned_class == 2 or assigned_class == 5:
            return 1
        if assigned_class == 3 or assigned_class == 4 :
            return 9
    else:
        return None  # No number found



