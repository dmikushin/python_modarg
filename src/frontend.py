#!/usr/bin/python3

from python_modarg import *
import numpy as np

def callback(a, i, result) :
	result.__setitem__(i, int(a) * 10)

def main() :
	length = 10
	
	result = backend(length, callback)

	for i in range(length) :
		print("%d vs %d" % (result[i], i * 10))
	
if __name__ == "__main__" :
	main()

