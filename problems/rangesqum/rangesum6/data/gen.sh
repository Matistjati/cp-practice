#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_treap.cpp

compile gen_rand.py

samplegroup
limits exclude=-1
sample 1

group g1 50
limits exclude=2
tc g1_1 gen_rand mode=random exclude=2 n=200000
tc g1_2 gen_rand mode=large_interval exclude=2 n=200000
tc g1_3 gen_rand mode=worst_case exclude=2 n=200000

group g2 1
limits exclude=1
tc g2_1 gen_rand mode=random exclude=1 n=200000
tc g2_2 gen_rand mode=large_interval exclude=1 n=200000
tc g2_3 gen_rand mode=worst_case exclude=1 n=200000

group g3 49
include_group g1
include_group g2
limits exclude=-1
tc 1
tc g3_1 gen_rand mode=random exclude=-1 n=200000
tc g3_2 gen_rand mode=large_interval exclude=-1 n=200000
tc g3_3 gen_rand mode=worst_case exclude=-1 n=200000
