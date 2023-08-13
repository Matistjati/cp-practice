#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua.cpp

compile gen_rand.py

samplegroup
limits maxn=100
sample 1
sample 2
sample 3

group g1allsmall 20
limits maxn=100000 maxv=100000
tc 2
tc 3
tc g1_1 gen_rand n=100000 maxv=100000 mode=long
tc g1_2 gen_rand n=100000 maxv=100000 tight=2 mode=random
tc g1_3 gen_rand n=100000 maxv=100000 tight=10 mode=random
tc g1_4 gen_rand n=100000 maxv=100000 tight=100 mode=random
tc g1_5 gen_rand n=100000 maxv=100000 tight=1000 mode=random

group g2smallcoord 20
limits maxn=100000
include_group g1allsmall
tc 1
tc g2_1 gen_rand n=100000 mode=long
tc g2_2 gen_rand n=100000 tight=2 mode=random
tc g2_3 gen_rand n=100000 tight=10 mode=random
tc g2_4 gen_rand n=100000 tight=100 mode=random
tc g2_5 gen_rand n=100000 tight=1000 mode=random

group g3larger 30
limits maxn=500000
include_group g2smallcoord
tc g3_1 gen_rand n=500000 mode=long
tc g3_2 gen_rand n=500000 tight=2 mode=random
tc g3_3 gen_rand n=500000 tight=10 mode=random
tc g3_4 gen_rand n=500000 tight=100 mode=random
tc g3_5 gen_rand n=500000 tight=1000 mode=random

group g4full 30
limits maxn=1000000
include_group g3larger
tc g4_1 gen_rand n=1000000 mode=long
tc g4_2 gen_rand n=1000000 tight=2 mode=random
tc g4_3 gen_rand n=1000000 tight=10 mode=random
tc g4_4 gen_rand n=1000000 tight=100 mode=random
tc g4_5 gen_rand n=1000000 tight=1000 mode=random
