#!/bin/bash
. ../../../testdata_tools/gen.sh

use_solution sqrt.cpp

compile gen_rand.py

samplegroup
limits maxn=100 maxq=100
sample 1

group group1 50
include_group sample
limits maxn=1000 maxq=1000
tc g1_1 gen_rand n=1 q=1000 p_query=0.5 mode=random
tc g1_2 gen_rand n=1000 q=1 p_query=0.5 mode=random
tc g1_3 gen_rand n=2 q=1000 p_query=0.5 mode=random
tc g1_4 gen_rand n=3 q=1000 p_query=0.5 mode=random
tc g1_5 gen_rand n=1000 q=1000 p_query=0.5 mode=random
tc g1_6 gen_rand n=1000 q=1000 p_query=0.001 mode=wide
tc g1_7 gen_rand n=1000 q=1000 p_query=0.5 mode=wide
tc g1_8 gen_rand n=1000 q=1000 p_query=0.999 mode=wide

group group2 50
include_group group1
tc g2_1 gen_rand n=300000 q=100000 p_query=0.5 mode=random
tc g2_2 gen_rand n=300000 q=100000 p_query=0.001 mode=wide
tc g2_3 gen_rand n=300000 q=100000 p_query=0.5 mode=wide
tc g2_4 gen_rand n=300000 q=100000 p_query=0.999 mode=wide
