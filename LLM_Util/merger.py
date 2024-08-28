import os

# Define the paths to your folders
removed_code_path = "removed_code"
llm_response_path = "llm_response"
merged_responses_path = "merged_responses"

# Create the merged_responses directory if it doesn't exist
os.makedirs(merged_responses_path, exist_ok=True)

# Iterate through each file in the removed_code folder
for removed_file in os.listdir(removed_code_path):
    if removed_file.startswith("removed_code_time_"):
        # Extract the time from the filename
        time_stamp = removed_file[len("removed_code_time_"):].replace(".blade.c", "")

        # Define the corresponding llm_response file name
        llm_file = f"llm_time_{time_stamp}.blade.c.txt"

        # Check if the corresponding llm_response file exists
        if os.path.exists(os.path.join(llm_response_path, llm_file)):
            # Define the merged file name
            merged_file_name = f"merged_time_{time_stamp}.blade.c.txt"

            # Open and read the contents of the removed_code file
            with open(os.path.join(removed_code_path, removed_file), 'r') as rc_file:
                removed_code_content = rc_file.read()

            # Open and read the contents of the llm_response file
            with open(os.path.join(llm_response_path, llm_file), 'r') as llm_file:
                llm_response_content = llm_file.read()

            # Create the merged file and write the contents
            with open(os.path.join(merged_responses_path, merged_file_name), 'w') as merged_file:
                merged_file.write("Query:")
                merged_file.write(removed_code_content)
                merged_file.write("\n\nLLM Response:\n\n")
                merged_file.write(llm_response_content)

            print(f"Merged file created: {merged_file_name}")

print("All files have been merged successfully!")
