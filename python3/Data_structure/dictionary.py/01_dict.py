thisdict = {
	"Brand": "Ford",
	"model": "Mustang",
	"year" : 1964
}
print(thisdict)

#ACCESSING ITEMS
#x = thisdict["model"]
x = thisdict.get("model")
print(x)

#Changing the value
thisdict["year"] = 2019

print(thisdict)

#Accessing through loops
for x in thisdict:
	print(x)

print()
print()

for x in thisdict.values():
	print(x)
