#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
sample 1
sample 2

group g1tiny 20
limits tinyupdate=1 tinyquery=1
tc g1_1 gen_rand tinyupdate=1 tinyquery=1 hi=10
tc g1_2 gen_rand tinyupdate=1 tinyquery=1
tc g1_3 gen_rand tinyupdate=1 tinyquery=1
tc g1_4 gen_rand tinyupdate=1 tinyquery=1

group g2tinyupdate 30
include_group g1tiny
limits tinyupdate=1
tc g2_1 gen_rand tinyupdate=1 hi=10
tc g2_2 gen_rand tinyupdate=1
tc g2_3 gen_rand tinyupdate=1
tc g2_4 gen_rand tinyupdate=1

group g3full 50
include_group g2tinyupdate
include_group sample
tc g3_1 gen_rand
tc g3_2 gen_rand
tc g3_3 gen_rand
tc g3_4 gen_rand