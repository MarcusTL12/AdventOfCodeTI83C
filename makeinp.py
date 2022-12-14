#!/usr/bin/env python3

import sys
import os

os.makedirs("build", exist_ok=True)

year = sys.argv[1]
day = sys.argv[2]
inpname = "input"
if len(sys.argv) >= 4:
    inpname = sys.argv[3]

inp_path = f"{year}/day{day}/{inpname}"
out_path = f"{year}/day{day}/{inpname}.h"

with open(inp_path) as inp_f:
    inp_s = inp_f.read()

with open(out_path, "w") as out_f:
    out_f.write("char input[] = {")
    for c in inp_s:
        i = ord(c)
        out_f.write(f"{i}, ")
        first = False
    out_f.write("0};\n")
