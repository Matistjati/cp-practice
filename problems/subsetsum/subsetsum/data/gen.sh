#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_bitset.cpp

compile gen_rand.py
compile gen_weighted.py

samplegroup
limits maxn=10 maxv=20
sample 1
sample 2
sample 3

group g1tiny 33
limits maxn=16 maxv=1000
tc 1
tc 2
tc 3
tc tinyrand1 gen_rand n=16 v=1000
tc tinyrand2 gen_rand n=16 v=1000
tc tinyrand3 gen_rand n=16 v=1000
tc tinyrand4 gen_rand n=16 v=1000
tc tinyrand5 gen_rand n=16 v=1000

group g2small 33
include_group g1tiny
limits maxn=100 maxv=1000
tc smallrand1 gen_rand n=100 v=1000
tc smallrand2 gen_rand n=100 v=1000
tc smallrand3 gen_rand n=100 v=1000

group g3medium 34
include_group g2small
limits maxn=4000 maxv=1000
tc mediumrand1 gen_rand n=4000 v=1000
tc mediumrand2 gen_rand n=4000 v=1000
tc mediumrand3 gen_rand n=4000 v=1000
tc mediumweight1 gen_rand n=4000 v=1000
tc mediumweight2 gen_rand n=4000 v=1000
