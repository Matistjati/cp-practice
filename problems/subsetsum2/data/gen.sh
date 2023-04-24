#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_bitsetsqrt.cpp

compile gen_rand.py

samplegroup
limits maxn=10 maxv=20
sample 1
sample 2
sample 3


group g1full 100
limits maxn=100000 maxv=100
tc 1
tc 2
tc 3
tc full1 gen_rand n=100000 v=100
tc full2 gen_rand n=100000 v=100
tc full3 gen_rand n=100000 v=100
tc full4 gen_rand n=100000 v=100
tc full5 gen_rand n=100000 v=100

