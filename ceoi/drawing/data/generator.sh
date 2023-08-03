#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../../testdata_tools/gen.sh

ulimit -s unlimited

use_solution drawing.cpp

MAXN=200000


samplegroup
limits maxn=$MAXN
sample 1
sample 2
sample 3

group group1 10
limits maxn=$MAXN minn=3 convex=1
tc_manual ../manual_tests/drawing.1a.in
tc_manual ../manual_tests/drawing.1b.in
tc_manual ../manual_tests/drawing.1c.in
tc_manual ../manual_tests/drawing.1d.in
tc_manual ../manual_tests/drawing.1e.in
tc_manual ../manual_tests/drawing.1f.in
tc_manual ../manual_tests/drawing.1g.in


group group2 15
include_group sample
limits maxn=4000
tc_manual ../manual_tests/drawing.2a.in
tc_manual ../manual_tests/drawing.2b.in
tc_manual ../manual_tests/drawing.2c.in
tc_manual ../manual_tests/drawing.2d.in
tc_manual ../manual_tests/drawing.2e.in
tc_manual ../manual_tests/drawing.2f.in
tc_manual ../manual_tests/drawing.2g.in
tc_manual ../manual_tests/drawing.2h.in
tc_manual ../manual_tests/drawing.2i.in
tc_manual ../manual_tests/drawing.2j.in
tc_manual ../manual_tests/drawing.2k.in
tc_manual ../manual_tests/drawing.2l.in
tc_manual ../manual_tests/drawing.2m.in
tc_manual ../manual_tests/drawing.2n.in

group group3 15
include_group group2
limits maxn=10000
tc_manual ../manual_tests/drawing.3a.in
tc_manual ../manual_tests/drawing.3b.in
tc_manual ../manual_tests/drawing.3c.in
tc_manual ../manual_tests/drawing.3d.in
tc_manual ../manual_tests/drawing.3e.in
tc_manual ../manual_tests/drawing.3f.in
tc_manual ../manual_tests/drawing.3g.in
tc_manual ../manual_tests/drawing.3h.in
tc_manual ../manual_tests/drawing.3i.in
tc_manual ../manual_tests/drawing.3j.in
tc_manual ../manual_tests/drawing.3k.in
tc_manual ../manual_tests/drawing.3l.in
tc_manual ../manual_tests/drawing.3m.in
tc_manual ../manual_tests/drawing.3n.in

group group4 35
include_group group3
limits maxn=80000
tc_manual ../manual_tests/drawing.4a.in
tc_manual ../manual_tests/drawing.4b.in
tc_manual ../manual_tests/drawing.4c.in
tc_manual ../manual_tests/drawing.4d.in
tc_manual ../manual_tests/drawing.4e.in
tc_manual ../manual_tests/drawing.4f.in
tc_manual ../manual_tests/drawing.4g.in
tc_manual ../manual_tests/drawing.4h.in
tc_manual ../manual_tests/drawing.4i.in
tc_manual ../manual_tests/drawing.4j.in
tc_manual ../manual_tests/drawing.4k.in
tc_manual ../manual_tests/drawing.4l.in
tc_manual ../manual_tests/drawing.4m.in
tc_manual ../manual_tests/drawing.4n.in

group group5 25
include_group group1
include_group group4
limits maxn=$MAXN
tc_manual ../manual_tests/drawing.5a.in
tc_manual ../manual_tests/drawing.5b.in
tc_manual ../manual_tests/drawing.5c.in
tc_manual ../manual_tests/drawing.5d.in
tc_manual ../manual_tests/drawing.5e.in
tc_manual ../manual_tests/drawing.5f.in
tc_manual ../manual_tests/drawing.5g.in
tc_manual ../manual_tests/drawing.5h.in
tc_manual ../manual_tests/drawing.5i.in
tc_manual ../manual_tests/drawing.5j.in
tc_manual ../manual_tests/drawing.5k.in
tc_manual ../manual_tests/drawing.5l.in
tc_manual ../manual_tests/drawing.5m.in
tc_manual ../manual_tests/drawing.5n.in