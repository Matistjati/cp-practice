#!/bin/bash
. ../../testdata_tools/gen.sh
ulimit -s unlimited

use_solution cheat.py

group full 100
tc_manual 1
