/*
Problem 6 - Sum square difference

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385

The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025

Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 ? 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

*/

#include <stdio.h>

int main(void) {

	int sum_of_squares = 0;
	int sum_to_be_squared = 0;
	int i;
	
	for(i = 1; i<=100;i++)
	{
		sum_of_squares+=i*i;
		sum_to_be_squared+=i;
	}

	sum_to_be_squared=sum_to_be_squared*sum_to_be_squared;
	
	printf("%d",sum_to_be_squared-sum_of_squares);

	return 0;
}
