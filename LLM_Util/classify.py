import os
import shutil

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
        return assigned_class
    else:
        return None  # No number found

def process_files_in_folder(input_folder, output_folder_5, output_folder_6):
    if not os.path.exists(output_folder_5):
        os.makedirs(output_folder_5)
    if not os.path.exists(output_folder_6):
        os.makedirs(output_folder_6)

    for filename in os.listdir(input_folder):
        if filename.endswith('.txt'):
            file_path = os.path.join(input_folder, filename)

            with open(file_path, 'r') as file:
                content = file.read()

            result = extract_imp_score_new_prompt(content)


            if result == 5:
                shutil.copy(file_path, os.path.join(output_folder_5, filename))
            elif result == 4:
                shutil.copy(file_path, os.path.join(output_folder_6, filename))

# Example usage
input_folder = 'merged_responses'
output_folder_5 = 'folder_5'
output_folder_6 = 'folder_4'

process_files_in_folder(input_folder, output_folder_5, output_folder_6)
