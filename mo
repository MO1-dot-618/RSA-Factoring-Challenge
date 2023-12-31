#!/usr/bin/python3
"""Module that factorize as many numbers as possible
 into a product of two smaller numbers."""
from sys import argv


def factorize(value):
    """"print a simple descomposition of an integer > 1"""
    if (value % 2) == 0:
        print("{:d}={:d}*2".format(value, value // 2))
        return
    i = 3
    a = divmod(value, i)
    while a[1]:
        i += 2
        a = divmod(value, i)
    print("{:d}={:d}*{:d}".format(value, a[0], i))

if len(argv) != 2:
    print("Usage: factors <file>")
    exit()

try:
    with open(argv[1]) as file:
        line = file.readline()
        while line != "":
            value = int(line.split('\n')[0])
            factorize(value)
            """print(line)"""
            line = file.readline()
except:
    print("Cannot open file {}".format(argv[1]))
