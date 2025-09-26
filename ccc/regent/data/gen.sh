#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution joshua.cpp

samplegroup
sample 1
sample 2

group full 100
include_group sample
tc_manual ../manual_tests/3.in
