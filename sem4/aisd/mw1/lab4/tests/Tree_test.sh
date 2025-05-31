#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <m> <type>"
    echo "  m - number of repetitions"
    echo "  type - type of tree (BST, RBT, Splay)"
    exit 1
fi

m=$1
type=$2

# Print CSV header
echo "n,op_index,key_comparisons,pointer_ops,current_height"

# Loop through each n value
for ((j=10000; j<=100000; j+=10000)); do
    for ((i=1; i<=m; i++)); do
        # Pipe input to main, line-by-line output parsing
        ./bin/IncreaseInputRandomGenerator "$j" | ./bin/main "$type" | while read -r op_index key_comparisons pointer_ops current_height; do
            echo "$j,$op_index,$key_comparisons,$pointer_ops,$current_height"
        done
    done
done
