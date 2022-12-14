#!/usr/bin/env python3

def makeinp(year, day, inpname):
    inp_path = f"{year}/day{day}/{inpname}"
    out_path = f"build/{inpname}.c"

    i_type = "unsigned int"
    i_width = 2

    with open(inp_path) as inp_f:
        inp_s = inp_f.read()

    while len(inp_s) % i_width != 0:
        inp_s += '\0'

    with open(out_path, "w") as out_f:
        out_f.write(i_type + " input[] = {")
        for i in range(0, len(inp_s), i_width):
            x = 0
            for j in range(i_width):
                x += 2**(8 * j) * ord(inp_s[i + j])
            out_f.write(f"{x}, ")
        out_f.write("0};\n")
