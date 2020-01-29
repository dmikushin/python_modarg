#!/usr/bin/python3

from python_tbb import *
import numpy as np

def callback(a, b) :
	b = int(a) * 10

def main() :
	length = 10
	result = stdvectorint(np.zeros(length, np.int32))
	
	backend(result, callback)

	for i in range(length) :
		print("%d vs %d" % (result[i], i * 10))
	
if __name__ == "__main__" :
	main()

