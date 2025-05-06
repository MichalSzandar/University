#!/bin/bash

# Size of groups
s_values=(3 5 7 9)

# Print header
echo "n s key_swaps key_comparisons execution_time"

# Loop through each n value
for ((j=100; j<=50000; j+=100)); do
    for s in "${s_values[@]}"; do
        for ((i=1; i<=50; i++)); do
            # Run the command and capture output
            output=$(./generators/RandomGenerator $j 55 | ./select_algorithms/select_experimental $s)

            # Extract key_swaps and key_comparisons from the output
            key_comparisons=$(echo $output | awk '{print $1}')
            key_swaps=$(echo $output | awk '{print $2}')
            execution_time=$(echo $output | awk '{print $3}')

            # Print the result in the desired format
            echo "$j $s $key_swaps $key_comparisons $execution_time"
        done
    done
done