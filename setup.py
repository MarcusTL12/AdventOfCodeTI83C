#!/usr/bin/env python3

import subprocess
import sys
import os

from makeinp import makeinp

year = sys.argv[1]
day = sys.argv[2]
part = sys.argv[3]

if len(sys.argv) >= 5:
    inpname = sys.argv[4]
else:
    inpname = "input"

ansi = False
compiler = "sdcc"
# compiler = "sccz80"

opt = 3

speed = ','.join(["sub32", "add32", "sub16", "lshift32", "rshift32",
                 "inlineints", "ucharmult", "intcompare", "longcompare"])
# speed = ""

flags = ["+ti83"]

if ansi:
    flags.append("-clib=ansi")

flags.append(f"-compiler={compiler}")

if compiler == "sccz80" and len(speed) > 0:
    flags.append(f"--opt-code-speed={speed}")

if compiler == "sccz80":
    flags.append(f"-O{opt}")
else:
    flags.append(f"-SO{opt}")

flags = ' '.join(flags)

cmake_command = ' '.join([
    "cmake ..",
    "-DCMAKE_C_COMPILER=zcc",
    f"-DCMAKE_C_FLAGS='{flags}'",
    f"-DYEAR={year}",
    f"-DDAY={day}",
    f"-DPART={part}",
    f"-DINPUT={inpname}",
])

os.makedirs("build", exist_ok=True)

makeinp(year, day, inpname)

os.chdir("build")

subprocess.call(cmake_command, shell=True)
