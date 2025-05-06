#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <k>"
    echo "  k - number of repetitions"
    exit 1
fi

# Assign argument to variable
k=$1

# Array of n values
n_values=(10 20 30 40 50 1000 2000 3000 4000 5000)

# Print header
echo "n key_swaps key_comparisons"

# Loop through each n value
for n in "${n_values[@]}"; do
    # Loop to run the command k times
    for ((i=1; i<=k; i++))
    do
        # Run the command and capture output
        output=$(./generators/RandomArrayGenerator $n | ./select_algorithms/DualPivotQS)

        # Extract key_swaps and key_comparisons from the output
        key_comparisons=$(echo $output | awk '{print $1}')
        key_swaps=$(echo $output | awk '{print $2}')

        # Print the result in the desired format
        echo "$n $key_swaps $key_comparisons"
    done
done