#!/bin/bash

# Print header
echo "n v key_comparisons execution_time"

for ((i=1000; i<=100000; i+=1000)); do
    v2=$((i / 2 + 20))
    v3=$((i - 20))
    v4=$((i + 20))
    v_values=(20 $v2 $v3 $v4)

    for v in "${!v_values[@]}"; do
        # Run the command and capture output
        output=$(./generators/IncreaseGenerator $i ${v_values[v]} | ./select_algorithms/binarysearch)

        # Extract key_swaps and key_comparisons from the output
        key_comparisons=$(echo $output | awk '{print $1}')
        execution_time=$(echo $output | awk '{print $2}')

        # Print the result in the desired format
        echo "$i $v $key_comparisons $execution_time"
    done
done