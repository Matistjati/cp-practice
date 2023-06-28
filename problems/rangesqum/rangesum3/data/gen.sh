#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2

group g1small 40
limits hi=1e5
tc g1_1 gen_rand hi=100000
tc g1_2 gen_rand hi=100000
tc g1_3 gen_rand hi=100000
tc g1_4 gen_rand hi=100000

group g2tiny 10
limits tinyupdate=1 tinyquery=1
tc g2_1 gen_rand tinyupdate=1 tinyquery=1 hi=10
tc g2_2 gen_rand tinyupdate=1 tinyquery=1
tc g2_3 gen_rand tinyupdate=1 tinyquery=1
tc g2_4 gen_rand tinyupdate=1 tinyquery=1

group g3tinyupdate 10
include_group g2tiny
limits tinyupdate=1
tc g3_1 gen_rand tinyupdate=1 hi=10
tc g3_2 gen_rand tinyupdate=1
tc g3_3 gen_rand tinyupdate=1
tc g3_4 gen_rand tinyupdate=1

group g4full 40
include_group g3tinyupdate
include_group sample
tc g4_1 gen_rand
tc g4_2 gen_rand
tc g4_3 gen_rand
tc g4_4 gen_rand