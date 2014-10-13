#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Magicsquare.h"


int main()
{
	time_t start,end;
    //seeding the random number generator
	srand(time(NULL)); 

	//initializing the counter to count the number of iterations
	int count=0;

	//dynamic allocation of memory at pointer location using malloc
	MagSquare_PTR mptr = (MagSquare_PTR)malloc(sizeof(MSQUARE_TYPE));


	//calling function to initialize the array
	initSquare( mptr, MAGICSIZE );

	//calling function to print the array
	printSquare( mptr , MAGICSIZE);
/*
	//calling function to calculate the sum of coloumns
     int i;
     for (i = 0 ;i < MAGICSIZE ; i++)
     {
          printf("The sum of Coloumn %d",(i+1));
          printf(" is ");
          printf("%d\n", sumColumn( i, mptr, MAGICSIZE ));
     }

     //calling function to calculate the sum of coloumns
     int j;
     for (j = 0 ;j < MAGICSIZE ; j++)
     {
          printf("The sum of Row %d",(j+1));
          printf(" is ");
          printf("%d\n", sumRow( j, mptr, MAGICSIZE ));
     }

     // calling function to calculate the sum of diagonal elememts
     int k;
     for (k = 0 ;k < 2; k++)
     {
          printf("The sum of diagonal %d",(k+1));
          printf(" is ");
          printf("%d\n", sumDiagonal( k, mptr, MAGICSIZE));
     }
     */
     
	//calling function to check weather the 2-D array is magic or not
	//int a = isMagic(mptr, MAGICSIZE );
	int a;

    time(&start);
	do{	
		//printf("Checking\n");
		a=isMagic(mptr, MAGICSIZE );//check if it's a magic square
		//printf("Entering conditions\n");
	if(a==0)//not a mgic square hence permute 
	{
		//printf("Entered Permute square\n");
		count=count+1;//increment the counter
		//calling the function to swap two locations
		permuteSquare(mptr , MAGICSIZE );
		//printf("Out of permute loop\n");
		//printSquare(mptr , MAGICSIZE);
		//printf("---------------------------------------------------------\n" );
		//check again if the matrix is a magic square
		//a=isMagic(mptr, MAGICSIZE );
		//printf("%lf\n",count);
		//printf("Not a magic square\n");
	}
	else if(a==1)//it is a magic square hence print
	{
		printf("This is the final Magic Square\n");
		printSquare( mptr , MAGICSIZE);
	}
    }while(a!=1);
    time(&end);
    double duration;
	//using the function difftime to calculate the time difference between start and end time
	duration = difftime(end,start);
	printf("%f It took following time to get a magic square\n",duration );
    //calling function to permute
    //permuteSquare(MagSquare_PTR x);
    printf("It took following iterations to find the magic square  %d\n",count);
    
	return (0);
}