#!/usr/bin/env bash
INPUT="$(readlink -f "$1")"
OUTPUT="$(readlink -f "$3")"
cd /home/random/n64/decomp/oot
tools/ido_recomp/linux/7.1/cc -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -Iassets -Ibuild -Wab,-r4300_mul -woff 649,838,712 -mips2 -O2 "$INPUT" -o "$OUTPUT"