#!/bin/bash

# Check if a file name is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

input_file="$1"
output_file="cleaned_${input_file}"

# Use sed to remove lines that start with // after optional whitespaces
sed '/^[[:space:]]*\/\//d' "$input_file" > "$output_file"
rm "$input_file"
mv "$output_file" "$input_file"


echo "All comment lines removed. Cleaned file saved as $input_file"
