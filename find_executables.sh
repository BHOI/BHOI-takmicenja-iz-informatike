#!/bin/bash

# Check if the file command is available
if ! command -v file &> /dev/null; then
    echo "file command not found. Please install it and try again."
    exit 1
fi

# Function to check files recursively
check_files() {
    local directory=$1
    for file in "$directory"/*; do
        if [ -d "$file" ]; then
            check_files "$file"  # Recursively check subdirectories
        elif [ -f "$file" ]; then
            file_type=$(file "$file")
            if [[ $file_type == *"ELF"* || $file_type == *"PE32 executable"* || $file_type == *"PE32"* ]]; then
                echo "$file"
            fi
        fi
    done
}

# Start checking from the current directory
check_files "$(pwd)"
