#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Magicsquare.h"


int main()
{
    //seeding the random number generator
	srand(time(NULL)); 
	//int count=0;
	//dynamic allocation of memory at pointer location using malloc
	MagSquare_PTR mptr = (MagSquare_PTR)malloc(sizeof(MSQUARE_TYPE));
	//calling function to initialize the array
	initSquare( mptr, MAGICSIZE );
	//calling function to print the array
	printSquare( mptr , MAGICSIZE);
	//calling function to check weather the 2-D array is magic or not
/*
	int a = isMagic(mptr, MAGICSIZE );
	do{		
	if(a==0)
	{
		count++;
		permuteSquare(mptr);
		//printSquare(mptr , MAGICSIZE);
		a=isMagic(mptr, MAGICSIZE );
	}
	else
	{
		printSquare( mptr , MAGICSIZE);
	}
    }while(a!=1);
    //calling function to permute
    //permuteSquare(MagSquare_PTR x);
    printf("%d\n",count);
    */
	return (0);
}