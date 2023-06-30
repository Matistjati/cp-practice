#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2
sample 3
sample 4

group full 100
include_group sample
tc g1_1 gen_rand
tc g1_2 gen_rand
tc g1_3 gen_rand
tc g1_4 gen_rand
tc g1_5 gen_rand mode="worstcase"
tc g1_6 gen_rand mode="worstcase"
tc g1_7 gen_rand mode="worstcase"
tc g1_8 gen_rand mode="worstcase"