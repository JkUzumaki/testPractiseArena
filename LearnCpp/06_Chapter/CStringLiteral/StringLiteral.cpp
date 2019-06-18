The string literals are stored in read only memory location. when working with string literals we dont need to worry about scoping issues as they gets destroyed at the end of the program they have static duration.

Hence,
	1. Use a non-const char array when you need a string variable that you can modify later.
	2. Use a pointer to a const string literal when you need a read-only string literal.

Rule: Feel free to use C-style string symbolic constants if you need read-only strings in your program, but always make them const!
