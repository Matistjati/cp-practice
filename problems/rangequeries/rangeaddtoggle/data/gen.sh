#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_lazy.cpp

compile gen_rand.py
compile gen_hard.py

samplegroup
sample 1

group full 100
include_group sample
tc g1_1 gen_rand 
tc g1_2 gen_hard weight_add=0
tc g1_3 gen_hard weight_add=2
tc g1_4 gen_hard weight_add=5
tc g1_5 gen_hard weight_add=8
