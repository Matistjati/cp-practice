#!/bin/bash
. ../../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua_fastest.cpp

compile gen_rand.py

samplegroup
limits q=1
sample 1
sample 2
sample 3

group g1 25
include_group sample
limits q=10
tc g1rand1 gen_rand q=10 mode="random"
tc g1rand2 gen_rand q=10 mode="random"
tc g1rand3 gen_rand q=10 mode="random"
tc g1tryhard1 gen_rand q=10 mode="tryhard"
tc g1tryhard2 gen_rand q=10 mode="tryhard"
tc g1tryhard3 gen_rand q=10 mode="tryhard"

group g2 25
include_group g1
limits q=50
tc g2rand1 gen_rand q=50 mode="random"
tc g2rand2 gen_rand q=50 mode="random"
tc g2rand3 gen_rand q=50 mode="random"
tc g2tryhard1 gen_rand q=50 mode="tryhard"
tc g2tryhard2 gen_rand q=50 mode="tryhard"
tc g2tryhard3 gen_rand q=50 mode="tryhard"

group g3 25
include_group g2
limits q=300
tc g3rand1 gen_rand q=300 mode="random"
tc g3rand2 gen_rand q=300 mode="random"
tc g3rand3 gen_rand q=300 mode="random"
tc g3tryhard1 gen_rand q=300 mode="tryhard"
tc g3tryhard2 gen_rand q=300 mode="tryhard"
tc g3tryhard3 gen_rand q=300 mode="tryhard"

group g4 25
include_group g3
limits q=1000
tc g4rand1 gen_rand q=1000 mode="random"
tc g4rand2 gen_rand q=1000 mode="random"
tc g4rand3 gen_rand q=1000 mode="random"
tc g4tryhard1 gen_rand q=1000 mode="tryhard"
tc g4tryhard2 gen_rand q=1000 mode="tryhard"
tc g4tryhard3 gen_rand q=1000 mode="tryhard"