#!/usr/bin/python

import argparse

import pdb
import sys
import os

algorithm_template_cc = "algorithm/simple/t532.cc"
algorithm_template_h = "algorithm/simple/t532.h"
algorithm_template_unittest = "testing/algorithm/t532_unittest.cc"

algorithm_location = "algorithm/simple/"
algorithm_location_unittest = "testing/algorithm/"
algorithm_text = "t532"

#-------------

text = "t532"
location = "algorithm/simple/"
location_unittest = "testing/algorithm/"

template_cc = "algorithm/simple/t532.cc"
template_h = "algorithm/simple/t532.h"
template_unittest = "testing/algorithm/t532_unittest.cc"

def write_file(location, template, filetype, filename, unittest = ""):
    fp = open(template, "rb")
    str = fp.read(10000)
    str = str.replace(text, filename)
    str = str.replace(text.upper(), filename.upper())
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

def select_algorithm2():
    global text
    global location
    global location_unittest

    global template_cc
    global template_h
    global template_unittest

    text = "t532"
    location = "algorithm2/"
    location_unittest = "testing/algorithm2/"

    template_cc = algorithm_template_cc
    template_h = algorithm_template_h
    template_unittest = algorithm_template_unittest

def select_algorithm():
    global text
    global location
    global location_unittest

    global template_cc
    global template_h
    global template_unittest

    text = algorithm_text
    location = algorithm_location
    location_unittest = algorithm_location_unittest 

    template_cc = algorithm_template_cc
    template_h = algorithm_template_h
    template_unittest = algorithm_template_unittest

def select_cxx():
    global text
    global location
    global location_unittest

    global template_cc
    global template_h
    global template_unittest

    text = "template4_18"
    location = "effective_modern_cxx/template4_18/"
    location_unittest = "testing/effective_modern_cxx/"

    template_cc = location + text + ".cc"
    template_h = location + text + ".h"
    template_unittest = location_unittest + text + "_unittest.cc"

#algirithm
#python copy_template.py item4 -t 0
#cxx
#python copy_template.py item4 -t 1
#algirithm2
#python copy_template.py item4 -t 2
if __name__ == "__main__":
    file = sys.argv[1]

    parser = argparse.ArgumentParser()
    parser.add_argument('file', metavar='N', type=str, nargs='+',
                        help='file')
    
    parser.add_argument("-t", "--type", type=int, choices=[0, 1, 2],
                        help="template type")
    args = parser.parse_args()
    #pdb.set_trace()   
    if args.type == 0:
        select_algorithm()
    elif args.type == 1:
        select_cxx()
        location = location.replace(text, file)
        if not os.path.exists(location):
            os.makedirs(location)
    elif args.type == 2:
        select_algorithm2()
        location = location.replace(text, file)
        if not os.path.exists(location):
            os.makedirs(location)
        location_unittest = location_unittest.replace(text, file)
        if not os.path.exists(location_unittest):
            os.makedirs(location_unittest)
    write_file_cc(file)
    write_file_h(file)
    write_file_unittest(file)
