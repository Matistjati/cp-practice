#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
limits maxn=10 maxq=10
sample 1

group full 100
limits maxn=400000 maxq=400000
include_group sample
tc g1_1 gen_rand 
tc g1_2 gen_rand
tc g1_3 gen_rand
tc g1_4 gen_rand
