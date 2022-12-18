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
compiler = "sdcc"
# compiler = "sccz80"

opt = 3

speed = ','.join(["sub32", "add32", "sub16", "lshift32", "rshift32",
                 "inlineints", "ucharmult", "intcompare", "longcompare"])
# speed = ""

command = ["zcc", "+ti83"]

if ansi:
    command.append("-clib=ansi")

command.append(f"-compiler={compiler}")
command.append(f"-o {out_path}")
command.append("-create-app")

if compiler == "sccz80" and len(speed) > 0:
    command.append(f"--opt-code-speed={speed}")

if compiler == "sccz80":
    command.append(f"-O{opt}")
else:
    command.append(f"-SO{opt}")

command.append(f"-Iutil")
command.append(src_path)

command = ' '.join(command)

print(command)

subprocess.call(command, shell=True)
