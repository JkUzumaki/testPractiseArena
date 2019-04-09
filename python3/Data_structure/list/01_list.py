thislist = ["apple", "banana", "cherry"]

# Used to print without any name
print(thislist)

# Used to print based on index
print(thislist[1])

#Changing the item in the list
thislist[1] = "potato"
print(thislist[1])
print(thislist)

#Accessing list through loop
count = 1
for x in thislist:
	print("Data ",count, " ",x)
	count += 1

#Checking if data exist in list without using loop
if "apple" in thislist:
	print("Yes apple data exist")
if "le" in thislist:
	print("Yes le data exist")
else:
	print("No le data exist")

#list length
print("The lenght of the thislist ",len(thislist))

#adding data to list at end (appending)
print("Appending is the process of data data addition at  the end of the thislist")
thislist.append("Tomato")
print(thislist)

#adding data to list based on the index
print()
print("inserting a element to list based on the index")
thislist.insert(1, "orange")
print(thislist)

#removal of elements in the list
