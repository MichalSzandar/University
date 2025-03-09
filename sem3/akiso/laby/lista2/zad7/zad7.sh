#!/bin/bash

# Script that changes the names of all files in the current directory to lowercase.
# If the file already has a lowercase name, it does nothing.

for file in *; do
    if [ -f "$file" ]; then
        new_name=$(echo "$file" | tr '[:upper:]' '[:lower:]')
        if [ "$file" != "$new_name" ]; then
            mv -- "$file" "$new_name"
        fi
    fi
done
