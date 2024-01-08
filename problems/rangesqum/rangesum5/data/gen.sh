#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2

group full 100
include_group sample
tc g1_1 gen_rand mode=random n=1000
tc g1_2 gen_rand mode=random
tc g1_3 gen_rand mode=worstcase
