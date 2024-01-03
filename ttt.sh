#!/bin/bash

# Loop through every [0-9]+-main.c file in the current directory
for file in [0-9]*-main.c; do
    # Check if the file exists and is a regular file
    if [ -f "$file" ]; then
        # Use sed to replace \" with "
        sed -i 's/\\\"/"/g' "$file"
        echo "Replaced \\\" in $file"
    fi
done
