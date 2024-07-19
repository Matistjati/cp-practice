#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_treap.cpp

compile gen_rand.py

samplegroup
sample 1

group g1 100
include_group sample
tc g1-1 gen_rand q=500000 i=100 e=5 p=20
tc g1-2 gen_rand q=500000 i=20 e=5 p=20
tc g1-3 gen_rand q=500000 i=1000 e=1 p=1000
tc g1-4 gen_rand q=500000 i=1000 e=1000 p=1
