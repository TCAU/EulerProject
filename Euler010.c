/*
Problem 10 - Summation of primes

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

Notes: 

Program takes about 30 seconds to generate answer.

Tried using Linked Lists but hit a wall with memory constraints so I went back to arrays, 
each time the index maxed out, I increased the size of the array more.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isprime (int* primesarray, int isvalueprime)
{
	int arrayindex = 0;
	if ((isvalueprime % 2)==0) return 0; //even number can't be primes

	while(primesarray[arrayindex]!=0) // array was memory set to 0, we're only looking at primes entered into array
	{
		if(isvalueprime%primesarray[arrayindex]==0)
		{
				return 0; //value is not prime
		}
		arrayindex++;
	}
	return isvalueprime; //value is prime 
}

int main(void) 
{
	int primes[200000];
	int primesarraysize = sizeof(primes);
	
	memset (primes, 0 , primesarraysize);

	long long int count = 2; // I start off including 2 as a prime
	int index = 0;
	int i;

	for (i = 3; i < 2000000; i++)
	{
//		printf("%llu \n",count);
		if( index == primesarraysize ) 
		{
			printf("arraygcc needs to be bigger");
			return 1; //exit since array for primes not big enough
		} 

		if (isprime(primes, i))
		{
			primes[index]=i;
			index++;
			count+= i;
		} 
	}

printf("index is at %d\n", index);
printf("%llu", count);

getchar(); // pauses cmd prompt
	
	return 0;
}


/*

//   I thought using a linked list would be a good idea because I don't know how many primes I would need.
//   However, in practice this uses way more memory and I run out of it before I get to the answer using default compiler settings

//   Tested for numbers under 10, 20 , 30 and should work for 2000000 if the compiler settings are changed. 
//   This method uses more memory and is not faster.


// Code (C version C11):

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node 
{
        int data;
        struct node *next;
}node;

int isprime (node* firstnode, node* currentnode, int isvalueprime)
{
	currentnode = firstnode;
	
	while (currentnode->next!=NULL)
	{
		if((isvalueprime % currentnode->data)==0)
		{
			//printf("%d is not prime\n",isvalueprime);
			return 0;
		}
		currentnode = currentnode->next;
	}
	
	if ((isvalueprime % 2)==0) return 0; //even number can't be primes
	
	return isvalueprime; //value is prime
}

int main(void) 
{

	double count = 2;
	int i;
	
	node* start = NULL; // all new pointers should be first set to NULL
	node* current = NULL;

	start = (node*)malloc(sizeof(node));	
	start->next=NULL;
	
	current = start;

	count = 2;

	for (i = 3; i != 200000; i++)
	{
		if (isprime(start,current,i))
		{
			current->data = i;
			current->next = (node*)malloc(sizeof(node));
			current = current->next;
			current->next = NULL;
			count += (double) i;
		} 
	}
	
	current = start;
	
	while(current->next!=NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}


printf("%f", count);

getchar(); // pauses cmd prompt
	
	return 0;
}

*/