#!/bin/bash

# Check if the correct number of arguments is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <m>"
    echo "  m - number of repetitions"
    exit 1
fi

# Number of repetitions
m=$1

# Print header
echo "n k key_swaps key_comparisons execution_time"

# Loop through each n value
for ((j=100; j<=50000; j+=100)); do
    # Loop to run the command m times
    k_values=(1 50 99)
    for k in "${k_values[@]}"; do
        for ((i=1; i<=m; i++)); do
            # Run the command and capture output
            output=$(./generators/RandomGenerator $j $k | ./select_algorithms/randomselect)

            # Extract key_swaps and key_comparisons from the output
            key_comparisons=$(echo $output | awk '{print $1}')
            key_swaps=$(echo $output | awk '{print $2}')
            execution_time=$(echo $output | awk '{print $3}')

            # Print the result in the desired format
            echo "$j $k $key_swaps $key_comparisons $execution_time"
        done
    done
done