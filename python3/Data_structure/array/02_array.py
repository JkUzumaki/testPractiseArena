from array import *
array1 = array('i', [10, 20, 30, 40, 50])
print(array1)
print()

#inserting the element
#	It will insert the element at the particular index and move the elements in the remaining index
array1.insert(1, 60)
#array1.insert(0,30)
array1[0] = 30
print(array1)

#Deleting the element 
array1.remove(30);
for x in array1:
	print(x)

#Search the array
index = array1.index(50)
print("The element 50 is present at ", index)
