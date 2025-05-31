#!/bin/bash

./tests/Tree_test.sh 10 BST > results/BST//BST_test.csv
./tests/Tree_test.sh 10 RBT > results/RBT/RBT_test.csv
./tests/Tree_test.sh 10 Splay > results/Splay/Splay_test.csv
#python ./charts/chartGenerator.py