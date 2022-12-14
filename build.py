#!/usr/bin/env python3

import subprocess
import sys
import os

os.makedirs("build", exist_ok=True)

year = sys.argv[1]
day = sys.argv[2]
part = sys.argv[3]

src_path = f"{year}/day{day}/part{part}.c"
out_path = f"build/{year}-{day}p{part}"

ansi = False
# compiler = "sdcc"
compiler = "sccz80"
opt = 3
speed = "sub32,add32,sub16,lshift32,rshift32,inlineints,ucharmult,intcompare,longcompare"

if ansi:
    clib_s = "-clib=ansi"
else:
    clib_s = ""

command = ' '.join(
    [f"zcc +ti83 {clib_s} -compiler={compiler} -o {out_path}",
     f"-create-app -O{opt} --opt-code-speed={speed} {src_path}"]
)

subprocess.call(command, shell=True)
