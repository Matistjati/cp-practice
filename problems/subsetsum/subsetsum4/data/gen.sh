#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_m3.cpp

compile gen_rand.py
compile gen_large_dev.py


samplegroup
sample 1
sample 2


group g1full 100
include_group sample
tc g1-1 gen_large_dev
tc g1-2 gen_rand n=500
tc g1-3 gen_rand n=500
tc g1-4 gen_rand n=500
tc_manual possible_1
tc_manual possible_2
tc_manual impossible_1
tc_manual impossible_2
