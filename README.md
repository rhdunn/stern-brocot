# Stern-Brocot Numbers

The Stern-Brocot numbers are the sequence:

	1, 1, 2, 1, 3, 2, 3, 1, 4, ...

## Building

This project provides a standard makefile project. You can build the program by
running:

	make

This requires a functional C++11 compiler such as GCC or clang.

## Generating the Numbers

You can generate the numbers by running:

	./stern_brocot NUMBER_OF_TERMS
	./stern_brocot NUMBER_OF_TERMS FILTER_BY_VALUE

For example, to generate the first `5` Stern-Brocot numbers you can run:

	./stern_brocot 5

The output is the sequence of numbers separated by a comma. For example:

	1,1,2,1,3,

The `FILTER_BY_VALUE` argument tells the program to output the positions in the
Stern-Brocot sequence where `FILTER_BY_VALUE` occurs. This is used to identify
patterns in the distribution of the numbers in the Stern-Brocot sequence.

## License Information

The Stern-Brocot project is released under the GPL version 3 or later license.

Copyright (C) 2014 Reece H. Dunn
