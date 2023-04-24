#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution prefix.cpp

compile gen_rand.py

samplegroup
limits maxn=100 maxq=100
sample 1

group naive 50
limits maxn=1000 maxq=1000
include_group sample
tc g1_1 gen_rand n=1 q=1000
tc g1_2 gen_rand n=1000 q=1
tc g1_3 gen_rand n=2 q=1000
tc g1_4 gen_rand n=3 q=1000
tc g1_5 gen_rand n=1000 q=1000
tc g1_6 gen_rand n=1000 q=1000

group full 50
limits maxn=300000 maxq=100000
include_group naive
tc g2_1 gen_rand n=300000 q=100000
tc g2_2 gen_rand n=300000 q=100000 t=1
