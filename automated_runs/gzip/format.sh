#!/bin/bash

# Check if filename is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <filename>"
  exit 1
fi

# Assign filename to a variable
filename="$1"

# Run clang-format with specific style options
clang-format -style="{ColumnLimit: 300, AllowShortFunctionsOnASingleLine: All, AllowShortIfStatementsOnASingleLine: true}" -i "$filename"

echo "File '$filename' has been formatted and sorted."
