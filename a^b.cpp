#include <stdio.h>

// Iterative solution to calculate pow(x, n) using
// binary operators
int power(int x, unsigned n)
{
	// initialize result by 1
	int pow = 1;

	// do till n is not zero
	while (n)
	{
		// if n is odd, multiply result by x
		if (n & 1)
			pow *= x;

		// divide n by 2
		n = n >> 1;

		// multiply x by itself
		x = x * x;
	}

	// return result
	return pow;
}

// main function
int main(void)
{
	int x = -2;
	unsigned n = 10;

	printf("pow(%d,%d) = %d", x, n, power(x, n));

	return 0;
}
