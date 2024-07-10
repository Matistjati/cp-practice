#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_lowmem.cpp

compile gen_rand.py
compile gen_mod.py
compile gen_no.py
compile gen_one.py

samplegroup
sample 1
sample 2
sample 3


group g1full 100
tc 1
tc 2
tc 3
tc full1 gen_rand n=4000 v=2000000
tc full2 gen_rand n=4000 v=2000000
tc full3 gen_no case=0
tc full4 gen_no case=1
tc full5 gen_no case=2
tc full6 gen_mod n=4000 v=450
tc full7 gen_mod n=4000 v=150
tc full8 gen_mod n=4000 v=30
tc full9 gen_one
