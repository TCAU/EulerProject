/*
Problem 12 - Highly divisible triangular number

Published on Friday, 8th March 2002, 06:00 pm; Solved by 104026


What is the value of the first triangle number to have over five hundred divisors?


The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

Let us list the factors of the first seven triangle numbers:

     1: 1
     3: 1,3
     6: 1,2,3,6
    10: 1,2,5,10
    15: 1,3,5,15
    21: 1,3,7,21
    28: 1,2,4,7,14,28

We can see that 28 is the first triangle number to have over five divisors.

Notes: 
I read the problem wrong at first, thought I was supposed to find a number with exactly 500 divisors... 
Took me a day to find out how to find # of divisors for a number: 
	- if all divisors are prime then the # of divisors is a power of 2
	- if prime divisor is found as the factor more than once (ex 3 times) then it's 3 * powers of 2 (primes numbers found only once)

Answer: 76576500

Code (C version C11):
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getdivisors ( int primes[], int arraylength, int initialvalue)
{

	int numofdivisors=1;
	if (initialvalue < 1) return 0;
	if (initialvalue == 1) return numofdivisors;

	int remainder = initialvalue;
	int index = 0;

	while (remainder!=1)
	{

		if (index>arraylength) 
		{
			printf("need more primes\n");
			return 0;
		}
	
		if(remainder%primes[index] == 0)
		{
			int factor = 2;
			remainder /= primes[index];
			
			while (remainder%primes[index] == 0)
			{
				factor++;
				remainder /= primes[index];
			}
			numofdivisors*=factor;
		}

		index++;
	}

	printf("%d has %d factors\n", initialvalue, numofdivisors);
	
	return numofdivisors;
}



int fillprimesarray ( int primes[], int startindex, int arraylength)
{
	int i;

	for (i = 3; startindex != arraylength; i++)
	{

		if (isprime(primes, i))
		{
			primes[startindex]=i;
//			printf("last prime added is %d \n", primes[startindex]);
			startindex++;
		} 
//	printf("index at %d \n", startindex);
	}

	return startindex;
}

int isprime ( int primesarray[], int isvalueprime)
{
	int i = 0;

	if ((isvalueprime % 2)==0) return 0; //even number can't be primes

	while(primesarray[i]!=0)
	{
		if(isvalueprime%primesarray[i]==0)
		{
				return 0;
		}
		i++;
	}

	return isvalueprime; //value is prime
}

int main(void) 
{

	int primes[30000];
	memset (primes, 0 , sizeof(primes));
	primes[0] = 2;
	int index = 1;

	int arraylength = sizeof(primes)/sizeof(primes[0]);

	index = fillprimesarray ( primes, index, arraylength );

//	printf("index is at %d\n", index);
//	printf("last prime added is %d\n", primes[index-1]);

	int highestnumofdivisors = 1;

	int trianglenumber = 1;
	int trianglecount = 2;

	while( (highestnumofdivisors < 500 ))
	{
		trianglenumber = trianglenumber + trianglecount;
		trianglecount++;

		highestnumofdivisors = getdivisors ( primes, arraylength, trianglenumber );
	}



	printf("the triangle number , %d, has %d divisors. \n", trianglenumber, highestnumofdivisors);


	getchar(); // pauses cmd prompt
	
	return 0;
}