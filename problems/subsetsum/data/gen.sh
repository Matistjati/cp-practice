#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution pisinger_preprocess.cpp

compile gen_rand.py
compile gen_weighted.py

samplegroup
limits maxn=10 maxv=20
sample 1

group g1small 10
limits maxn=100 maxv=1000
tc 1
tc smallrand1 gen_rand n=100 v=1000
tc smallrand2 gen_rand n=100 v=1000
tc smallrand3 gen_rand n=100 v=1000

group g2medium 30
include_group g1small
limits maxn=4000 maxv=1000
tc mediumrand1 gen_rand n=1000 v=1000
tc mediumrand2 gen_rand n=1000 v=1000
tc mediumrand3 gen_rand n=1000 v=1000
tc mediumweight1 gen_weighted n=1000 v=1000
tc mediumweight2 gen_weighted n=1000 v=1000

group g3large 30
include_group g2medium
limits maxn=10000 maxv=1000
tc largerand1 gen_rand n=10000 v=1000
tc largerand2 gen_rand n=10000 v=1000
tc largerand3 gen_rand n=10000 v=1000
tc largeweight1 gen_weighted n=10000 v=1000
tc largeweight2 gen_weighted n=10000 v=1000

group g4huge 30
include_group g3large
limits maxn=100000 maxv=1000
tc hugerand1 gen_rand n=100000 v=1000
tc hugerand2 gen_rand n=100000 v=1000
tc hugerand3 gen_rand n=100000 v=1000

group g5hugest 30
include_group g4huge
limits maxn=100000 maxv=1000
tc hugestrand1 gen_rand n=100000 v=1000
tc hugestrand2 gen_rand n=100000 v=1000
tc hugestrand3 gen_rand n=100000 v=1000
