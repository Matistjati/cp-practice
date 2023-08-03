#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution measures.cpp

MAXN=200000
MAXM=200000


samplegroup
limits maxn=$MAXN maxm=$MAXM increasing=0
sample 1
sample 2
sample 3

group group1 10
limits maxn=2000 maxm=10 increasing=0
tc 1
tc 2
tc 3
tc_manual ../manual_tests/measures.1a.in
tc_manual ../manual_tests/measures.1b.in
tc_manual ../manual_tests/measures.1c.in
tc_manual ../manual_tests/measures.1d.in
tc_manual ../manual_tests/measures.1e.in
tc_manual ../manual_tests/measures.1f.in
tc_manual ../manual_tests/measures.1g.in
tc_manual ../manual_tests/measures.1h.in


group group2 14
include_group group1
limits maxn=$MAXN maxm=10 increasing=0
tc_manual ../manual_tests/measures.2a.in
tc_manual ../manual_tests/measures.2b.in
tc_manual ../manual_tests/measures.2c.in
tc_manual ../manual_tests/measures.2d.in
tc_manual ../manual_tests/measures.2e.in
tc_manual ../manual_tests/measures.2f.in
tc_manual ../manual_tests/measures.2g.in
tc_manual ../manual_tests/measures.2h.in

group group3 35
limits maxn=0 maxm=$MAXM increasing=1
tc_manual ../manual_tests/measures.3a.in
tc_manual ../manual_tests/measures.3b.in
tc_manual ../manual_tests/measures.3c.in
tc_manual ../manual_tests/measures.3d.in
tc_manual ../manual_tests/measures.3e.in
tc_manual ../manual_tests/measures.3f.in
tc_manual ../manual_tests/measures.3g.in
tc_manual ../manual_tests/measures.3h.in
tc_manual ../manual_tests/measures.3i.in
tc_manual ../manual_tests/measures.3j.in
tc_manual ../manual_tests/measures.3k.in
tc_manual ../manual_tests/measures.3l.in
tc_manual ../manual_tests/measures.3m.in
tc_manual ../manual_tests/measures.3n.in
tc_manual ../manual_tests/measures.3o.in
tc_manual ../manual_tests/measures.3p.in
tc_manual ../manual_tests/measures.3q.in

group group4 41
include_group group3
limits maxn=0 maxm=$MAXM increasing=0
tc_manual ../manual_tests/measures.4a.in
tc_manual ../manual_tests/measures.4b.in
tc_manual ../manual_tests/measures.4c.in
tc_manual ../manual_tests/measures.4d.in
tc_manual ../manual_tests/measures.4e.in
tc_manual ../manual_tests/measures.4f.in
tc_manual ../manual_tests/measures.4g.in
tc_manual ../manual_tests/measures.4h.in
tc_manual ../manual_tests/measures.4i.in
tc_manual ../manual_tests/measures.4j.in
tc_manual ../manual_tests/measures.4k.in
tc_manual ../manual_tests/measures.4l.in
tc_manual ../manual_tests/measures.4m.in
tc_manual ../manual_tests/measures.4n.in
tc_manual ../manual_tests/measures.4o.in
tc_manual ../manual_tests/measures.4p.in
tc_manual ../manual_tests/measures.4q.in