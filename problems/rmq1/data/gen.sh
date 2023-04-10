#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_segtree.cpp

compile gen_rand.py

samplegroup
sample 1

MAXN=100000
MAXQ=$MAXN

group full 100
tc 1
tc rand1 gen_rand n=$MAXN q=$MAXQ
tc rand2 gen_rand n=$MAXN q=$MAXQ
tc rand3 gen_rand n=$MAXN q=$MAXQ
tc rand4 gen_rand n=$MAXN q=$MAXQ
tc rand5 gen_rand n=$MAXN q=$MAXQ
tc rand6 gen_rand n=$MAXN q=$MAXQ
tc rand7 gen_rand n=$MAXN q=$MAXQ
