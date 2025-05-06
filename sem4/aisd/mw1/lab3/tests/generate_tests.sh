#!/bin/bash

# Number of reps
m=50

# Compile all cpp programs
make all

# Print header
echo "generating test results ..."

# test random select
#./tests/test_randomselect.sh $m > results/randomselect/randomselect_test.csv 2> out

# test select
#./tests/test_select.sh $m > results/select/select_test.csv 2> out

# test select experimental
#./tests/select_experimental_test.sh > results/select_experimental/select_experimental_test.csv 2> out

# test binary search
#./tests/binary_search_test.sh > results/binarysearch/bs_test.csv 2> out

# test binary search experimental
#./tests/binary_search_experimental_test.sh > results/binarysearch/bs_experimental_test.csv 2> out

# test quick sort
./tests/qs_test.sh $m > results/quick_sort/qs_test.csv 2> out

# test dual pivot quick sort 
./tests/dual_pivot_qs_test.sh $m > results/dual_pivot_qs/dual_pivot_qs_test.csv 2> out

rm out

echo "all tests have been generated in results directory"

# Clean up
make clean