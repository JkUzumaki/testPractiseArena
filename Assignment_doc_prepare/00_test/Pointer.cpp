// POINTER
Memory leak:
	1. It occur when memory allocated are not freed.
	2. It causes wastage of memory and may lead to potential fatal out of memory.

Memory corruption:
	1. It occur when program write data to wrong memory location, It may override the data that was present previously.
	
Both these problems comes under pointer.

Note:
	If a pointer points to a memory thats is been freed or assigned non zero integer or floating value, its a dangerous way of corrupting the memory.
	
Problems caused by pointer:
	1. Copying a pointer does not copy a object, leading to suprises if two pointers points to the same object.
	2. Destroying a pointer does not destroy its object, it can lead to memory leak.
	3. Destroying an object without destroying a pointer to it leads to dangling pointer, which causes undefined behaviour.
	4. Creating a pointer without initializing it leads to wild pointer as its use may lead to undefined behaviour.
	
How to check where the program crashes:
	
	