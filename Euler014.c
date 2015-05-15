/*
Problem 14 - Longest Collatz sequence
Published on Friday, 5th April 2002, 06:00 pm; Solved by 109073

The following iterative sequence is defined for the set of positive integers:

n Å® n/2 (n is even)
n Å® 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 Å® 40 Å® 20 Å® 10 Å® 5 Å® 16 Å® 8 Å® 4 Å® 2 Å® 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

Notes: 
	Problems are getting too big to brute force...
*/

#include <stdio.h>
#include <string.h>

// first version took too long to find the answer, decided to implement a cache that will save even numbers,
// since even numbers will always return the same value
// I'll need a way to make higher even numbers replace lower ones - done

int main(void)
{
	long long int start = 2;
	long long int startcopy , collatzsum;
	long long int largestcollatz = 0;
	long long int startnumberwithlargestcollatz;
	
	long long int cache[500], cachereturn[500];		
	int index = 500;
	int i, j;
	int cachewasfound;
	
	while ( start < 1000000 )
	{
		collatzsum = 0;
		cachewasfound = 0;
		startcopy = start;
		
		while(startcopy !=1)
		{
			if((startcopy % 2)==0)
			{	
//				printf("%llu is even\n",startcopy);
				for(j = 499; j>=index ; j--)
				{
					if (startcopy == cache[j])
					{
//						printf("cache was found, %llu had a return value of %llu originating from %llu added to %llu\n", start, cachereturn[j], cache[j], collatzsum);

						startcopy = 1;
						collatzsum+=cachereturn[j];
						cachewasfound = 1;
					}
				}
				if(cachewasfound == 0)
				{
					startcopy /=2;
					collatzsum++;
				}
			}
			else
			{
				startcopy = (3 * startcopy )+1;
				collatzsum++;
			}
		}
	
		if ( (startcopy == 1) && (start%2==0) && (index > 0) ) 
		{
			index--;
			cache[index] = start;
			cachereturn[index] = collatzsum;
//			printf("%llu with return value of %llu was indexed at %d\n", start, collatzsum, index);
		}

		if ( (startcopy == 1) && ( start % 2 == 0 ) && ( index < 0 ) ) 
		{
				for(j = 499; (j>=index) && cachewasfound ; j--)
				{
					if (collatzsum > cachereturn[j])
					{
//						printf("%llu with return value of %llu is replacing index %d\n", start, collatzsum, j);
						cache[j] = start;
						cachereturn[j] = collatzsum;
						cachewasfound = 0;
					}
				}
		}
		
		if( largestcollatz < collatzsum )
		{		
			largestcollatz = collatzsum;
			startnumberwithlargestcollatz = start;
		}
//		printf("collatzsum for %llu is at %d\n", start, collatzsum);

		start++;
	}
	printf("%llu has the largest collatz sum of %llu", startnumberwithlargestcollatz, largestcollatz);
	
//outputting cache
/*
	for (i = 0; i < 500; i++)
	{
		printf("index %d has %llu as a cache value and %llu as a return value \n", i , cache[i], cachereturn[i]);
	}
*/	
	return 0;
}