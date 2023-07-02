#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
sample 1

group g1noupdatenice 25
limits noupdate=1
tc g1_1 gen_rand mode="random" noupdates=1
tc g1_2 gen_rand mode="random" noupdates=1
tc g1_3 gen_rand mode="manyYes" noupdates=1

group g2noupdate 25
limits noupdate=1
include_group g1noupdatenice
tc_manual powtwokiller

group g3nice 25
include_group sample
tc g2_1 gen_rand mode="random"
tc g2_2 gen_rand mode="random"
tc g2_3 gen_rand mode="random"
tc g2_4 gen_rand mode="random"
tc g1_3

group full 25
include_group g2noupdate
include_group g3nice
tc_manual powtwokillerupdate