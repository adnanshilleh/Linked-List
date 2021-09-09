# Homework 1: simple linked list

The following should work when you are done with your assignment:

```
$ make
$ ./test
$ make clean
```

Your `main.c` must include a comprehensive test suite.
We will test with our own `main.c` by doing:

```
$ mv main.c main.c.saved
$ cp ../ourmain.c main.c
$ make
$ ./test
...our unit tests run here
$ mv main.c.saved main.c
```

You must implement all relevant files. We will test by compiling our test program with your .h files, and with your .c implementation files, if you implement them. Remember that your program must compile with the following gcc flags, or it is unlikely your submission will compile:

```
-Wall -Wextra -Werror
```

Please also ensure that you test for memory usage mistakes with valgrind.
You must follow the structuring guidance of your C code spelled out in the [resources](https://github.com/gwu-cs-os/resources/blob/master/c.md).

## Specification

Please see `csci3411_hw1.pdf` for the homework specification.

## Grading

Please "level up" your implementation through the following.
This is a "guide" to a path you can take to adding more and more features.

- **Level 0 (10%):**
	Compilation and creation of a linked list.
- **Level 1 (10%):**
	Addition of an item, and the corresponding length being calculated.
- **Level 2 (10%):**
	Simple contains with a single item list.
- **Level 3 (10%):**
	Ensuring destroy does not destroy a list with items in it.
- **Level 4 (15%):**
	Add multiple items.
- **Level 5-7 (5% each):**
	...and ensure contain works within them with items of various types.
- **Level 8 (15%):**
	Add and remove to properly retrieve items.
- **Level 9 (15%):**
	Properly add, remove, and destroy a list.

Don't forget to properly test your submission, both including all edge cases in the code, and ensuring the you properly pushed all code onto github.
