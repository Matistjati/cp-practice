#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
limits exclude=-1
sample 1
sample 2

group g1 25
limits exclude=1
tc g1_1 gen_rand mode=random n=200000 exclude=1
tc g1_2 gen_rand mode=large n=200000 exclude=1
tc g1_3 gen_rand mode=zigzag z=0 n=200000 exclude=1
tc g1_4 gen_rand mode=zigzag z=1 n=200000 exclude=1


group g2 50
limits exclude=2
tc 1
tc g2_1 gen_rand mode=random n=200000 exclude=2
tc g2_2 gen_rand mode=large n=200000 exclude=2
tc g2_3 gen_rand mode=zigzag z=0 n=200000 exclude=2
tc g2_4 gen_rand mode=zigzag z=1 n=200000 exclude=2

group g3 25
limits exclude=-1
include_group sample
include_group g1
include_group g2
tc g3_1 gen_rand mode=random n=200000 exclude=-1
tc g3_2 gen_rand mode=large n=200000 exclude=-1
tc g3_3 gen_rand mode=zigzag z=0 n=200000 exclude=-1
tc g3_4 gen_rand mode=zigzag z=1 n=200000 exclude=-1
