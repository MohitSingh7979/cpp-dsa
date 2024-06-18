#!/bin/bash

# File to store the last used filename
last_file=".last_file"

# Check if an argument is provided
if [ $# -eq 1 ]; then
    # Set the variable to the provided argument
    file=$1
    echo "$file" > "$last_file"
    echo "Variable file set to: $file"
elif [ -f "$last_file" ]; then
    # Use the last stored value if no argument provided
    file=$(cat "$last_file")
    echo "Using last stored variable file: $file"
else
    echo "Usage: $0 <new_value>"
    exit 1
fi

# Compile and execute if a file name is provided
if [ -n "$file" ]; then
    g++ "$file".cpp -o "$file" && ./"$file".exe
else
    echo "Error: No file name provided"
fi

# remove executable file
rm "$file".exe
