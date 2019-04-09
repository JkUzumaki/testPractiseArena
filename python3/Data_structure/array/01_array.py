# Array is a container
# It can hold fix number of items and they should be of the same type
# 
# ELEMENT:
#	Each item stored in an array is called an element
# INDEX:
#	Each location of an element in an array has a numerical index, which is used to identify the element
#

from array import *
# SYNTAX
#	arrayName = array(typecode, [Initializers])

# array1 = array('i', [10, 20, 30, 40, 50])
array1 = array('f', [10.5, 20.65, 30.89, 40.9003, 50.878587])

for x in array1:
	print(x)
