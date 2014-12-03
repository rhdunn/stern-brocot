# Stern-Brocot Numbers

The Stern-Brocot numbers are the sequence:

	1, 1, 2, 1, 3, 2, 3, 1, 4, ...

## Building

This project provides a standard makefile project. You can build the program by
running:

	make

This requires a functional C++11 compiler such as GCC or clang.

## Listing the Numbers

You can generate the numbers by running:

	./stern_brocot list NUMBER_OF_TERMS

For example, to generate the first `5` Stern-Brocot numbers you can run:

	$ ./stern_brocot list 5
	1,1,2,1,3,

## Filtering the Numbers

You can list the positions of a given number by running:

	./stern_brocot filter0 NUMBER_OF_TERMS FILTER_BY_VALUE
	./stern_brocot filter1 NUMBER_OF_TERMS FILTER_BY_VALUE


The `FILTER_BY_VALUE` argument tells the program to output the positions in the
Stern-Brocot sequence where `FILTER_BY_VALUE` occurs.

The `filter0` command uses the original Stern-Brocot sequence. The `filter1`
command offsets the indices by 1, so you have `t_1 = 1, t_2 = 1, t_3 = 2, ...`.

## Finding Number Sequences

You can find the exponential sequences contained within a given number
distribution by running:

	./stern_brocot sequences NUMBER_OF_TERMS FILTER_BY_VALUE

For example:

	$ ./stern_brocot sequences 10000 3
	5,7,

## License Information

The Stern-Brocot project is released under the GPL version 3 or later license.

Copyright (C) 2014 Reece H. Dunn
