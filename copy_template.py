#!/usr/bin/python

import sys

template_cc = "algorithm/simple/t532.cc"
template_h = "algorithm/simple/t532.h"
template_unittest = "testing/algorithm/t532_unittest.cc"

location = "algorithm/simple/"
location_unittest = "testing/algorithm/"

def write_file(location, template, filetype, filename, unittest = ""):
    fp = open(template, "rb")
    str = fp.read(10000)
    str = str.replace("t532", filename)
    str = str.replace("T532", filename.upper())
    fp.close()

    out = open(location + filename + unittest + filetype, "wb")
    out.write(str)
    out.close()

def write_file_cc(filename):
    write_file(location, template_cc, ".cc", filename)

def write_file_h(filename):
    write_file(location, template_h, ".h", filename)

def write_file_unittest(filename):
    write_file(location_unittest, template_unittest, ".cc", filename, "_unittest")

if __name__ == "__main__":
    file = sys.argv[1]
    write_file_cc(file)
    write_file_h(file)
    write_file_unittest(file)