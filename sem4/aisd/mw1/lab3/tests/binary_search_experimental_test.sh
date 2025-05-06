#!/bin/bash

# Print header
echo "n key_comparisons execution_time"

for ((i=1000; i<=100000; i+=1000)); do
    for ((j=0; j<50; j+=1)); do
        # Run the command and capture output
        output=$(./generators/IncreaseRandomGenerator $i | ./select_algorithms/binarysearch)

        # Extract key_swaps and key_comparisons from the output
        key_comparisons=$(echo $output | awk '{print $1}')
        execution_time=$(echo $output | awk '{print $2}')

        # Print the result in the desired format
        echo "$i $key_comparisons $execution_time"
    done
done