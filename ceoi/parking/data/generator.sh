#!/usr/bin/env bash

PPATH=$(realpath ..)
. ../testdata_tools/gen.sh

ulimit -s unlimited

use_solution parking.cpp

MAXN=200000
MAXM=200000


samplegroup
limits maxn=$MAXN maxm=$MAXM no_one=0 m_large=0
sample 1
sample 2
sample 3

group group1 10
limits maxn=$MAXN maxm=4 no_one=0 m_large=0
tc_manual ../manual_tests/parking.1a.in
tc_manual ../manual_tests/parking.1b.in
tc_manual ../manual_tests/parking.1c.in
tc_manual ../manual_tests/parking.1d.in
tc_manual ../manual_tests/parking.1e.in
tc_manual ../manual_tests/parking.1f.in
tc_manual ../manual_tests/parking.1g.in
tc_manual ../manual_tests/parking.1h.in
tc_manual ../manual_tests/parking.1i.in
tc_manual ../manual_tests/parking.1j.in


group group2 10
limits maxn=$MAXN maxm=$MAXM no_one=0 m_large=1
tc_manual ../manual_tests/parking.2a.in
tc_manual ../manual_tests/parking.2b.in
tc_manual ../manual_tests/parking.2c.in
tc_manual ../manual_tests/parking.2d.in
tc_manual ../manual_tests/parking.2e.in

group group3 25
limits maxn=1000 maxm=$MAXM no_one=1 m_large=0
tc_manual ../manual_tests/parking.3a.in
tc_manual ../manual_tests/parking.3b.in
tc_manual ../manual_tests/parking.3c.in
tc_manual ../manual_tests/parking.3d.in
tc_manual ../manual_tests/parking.3e.in
tc_manual ../manual_tests/parking.3f.in
tc_manual ../manual_tests/parking.3g.in
tc_manual ../manual_tests/parking.3h.in
tc_manual ../manual_tests/parking.3i.in

group group4 15
include_group group3
limits maxn=$MAXN maxm=$MAXM no_one=1 m_large=0
tc_manual ../manual_tests/parking.4a.in
tc_manual ../manual_tests/parking.4b.in
tc_manual ../manual_tests/parking.4c.in
tc_manual ../manual_tests/parking.4d.in
tc_manual ../manual_tests/parking.4e.in
tc_manual ../manual_tests/parking.4f.in
tc_manual ../manual_tests/parking.4g.in
tc_manual ../manual_tests/parking.4h.in
tc_manual ../manual_tests/parking.4i.in

group group5 25
include_group group3
limits maxn=1000 maxm=$MAXM no_one=0 m_large=0
tc_manual ../manual_tests/parking.5a.in
tc_manual ../manual_tests/parking.5b.in
tc_manual ../manual_tests/parking.5c.in
tc_manual ../manual_tests/parking.5d.in
tc_manual ../manual_tests/parking.5e.in
tc_manual ../manual_tests/parking.5f.in
tc_manual ../manual_tests/parking.5g.in
tc_manual ../manual_tests/parking.5h.in
tc_manual ../manual_tests/parking.5i.in
tc_manual ../manual_tests/parking.5j.in
tc_manual ../manual_tests/parking.5k.in
tc_manual ../manual_tests/parking.5l.in
tc_manual ../manual_tests/parking.5m.in
tc_manual ../manual_tests/parking.5n.in
tc_manual ../manual_tests/parking.5o.in
tc_manual ../manual_tests/parking.5p.in
tc_manual ../manual_tests/parking.5r.in
tc_manual ../manual_tests/parking.5s.in
tc_manual ../manual_tests/parking.5t.in
tc_manual ../manual_tests/parking.5u.in
tc_manual ../manual_tests/parking.5v.in
tc_manual ../manual_tests/parking.5w.in
tc_manual ../manual_tests/parking.5x.in

group group6 15
include_group sample
include_group group1
include_group group2
include_group group4
include_group group5
limits maxn=$MAXN maxm=$MAXM no_one=0 m_large=0
tc_manual ../manual_tests/parking.6a.in
tc_manual ../manual_tests/parking.6b.in
tc_manual ../manual_tests/parking.6c.in
tc_manual ../manual_tests/parking.6d.in
tc_manual ../manual_tests/parking.6e.in
tc_manual ../manual_tests/parking.6f.in
tc_manual ../manual_tests/parking.6g.in
tc_manual ../manual_tests/parking.6h.in
tc_manual ../manual_tests/parking.6i.in
tc_manual ../manual_tests/parking.6j.in
tc_manual ../manual_tests/parking.6k.in
tc_manual ../manual_tests/parking.6l.in
tc_manual ../manual_tests/parking.6m.in
tc_manual ../manual_tests/parking.6n.in
tc_manual ../manual_tests/parking.6o.in
tc_manual ../manual_tests/parking.6p.in
tc_manual ../manual_tests/parking.6r.in
tc_manual ../manual_tests/parking.6s.in
tc_manual ../manual_tests/parking.6t.in
tc_manual ../manual_tests/parking.6u.in
tc_manual ../manual_tests/parking.6v.in
tc_manual ../manual_tests/parking.6w.in
tc_manual ../manual_tests/parking.6x.in
