//including the user defined library
#include "Magicsquare.h"

//srand(time(NULL));//seed the random number generator 

//function for allocating random numbers to the 2-D array
void initSquare( MagSquare_PTR x, int magicsquaresize )
{
	srand(time(NULL));//seed the random number generator 
	int m,i,j;
	//int i,l;
    //initilizing the array for random number generation
	int a[magicsquaresize*magicsquaresize];
	for (m=0; m<(magicsquaresize*magicsquaresize); m++)
	{
		a[m]=0;
	}
	/*Random(magicsquaresize,a);
  		  for (l=0;l<(magicsquaresize*magicsquaresize);l++)
  			{
  	  			printf("%d\n",a[l]);
  	   		}*/
	//int n=magicsquaresize*magicsquaresize;
	//int y[n]=random(n)
     for(i=0; i < magicsquaresize; i++)
      {
      	 //srand(time(NULL));//seed the random number generator 
         for(j=0; j < magicsquaresize; j++) 
  		  {

  		  		//*x[i][j] =1 + rand( ) % (magicsquaresize*magicsquaresize);  
  		  		/*l=Random(magicsquaresize,a);
  		  		printf("%d\n",l);*/

  		  		*x[i][j]=Random(magicsquaresize,a);	
  		  		//printf("%d\n",*x[i][j] );		  				   	
  		  }
	  }
}

//function to print the magic square matrix
void printSquare(MagSquare_PTR x, int magicsquaresize )
{
	int i,j;
	  for(i = 0; i < magicsquaresize; i++)     // looping to print the 2-D matrix
     {
     	for (j = 0; j < magicsquaresize; j++)
     	{
     		printf("  %d",*x[i][j]);        
     	}
     	printf("\n");
     }
}

//function to print the sum of coloumn elements in magic box
int sumColumn( int column, MagSquare_PTR x, int magicsquaresize )
{
	int i,sum=0;
	for(i = 0; i < magicsquaresize; i++)
	{
		sum = sum + *x[i][column];
	}
	return sum;
}

//function to print the sum of row elements in magic box
int sumRow(int row, MagSquare_PTR x, int magicsquaresize)
{
	int i,sum=0;
	for(i = 0; i < magicsquaresize; i++)
	{
		sum = sum + *x[row][i];
	}
	return sum;
}

//function to print the sum of diagonal elements
int sumDiagonal( int diagonal, MagSquare_PTR x, int magicsquaresize )
{
	int i,j,sum=0;
	if(diagonal==0)
	{
		for (i = 0; i < magicsquaresize; i++)
		{
			sum = sum + *x[i][i];
		}
	}

	if(diagonal==1)
	{
		i=0;
		j=(magicsquaresize-1);
		while(i != magicsquaresize)
		{
			sum = sum + *x[i][j];
			i=i+1;
			j=j-1;
          }
				
			
	}
	return sum;
}

// function to check if the square is magic or not
int isMagic(MagSquare_PTR x, int magicsquaresize )
{
	int n = (magicsquaresize * ((magicsquaresize*magicsquaresize)+1));
	int i,flag = 0;
	for (i = 0 ;i < magicsquaresize ; i++)
	{
		if (n == sumColumn( i, x, magicsquaresize ))
		{
			flag =1;
		}
	}
	while (flag == 1)
	{
		for (i = 0 ;i < magicsquaresize ; i++)
	{
		if (n == sumRow( i, x, magicsquaresize))
		{
			flag = 1;
		}

	}
	}
    while (flag == 1)
    {
		for (i= 0 ;i < 2; i++)
		{
			if (n == sumDiagonal( i, x, magicsquaresize))
			{
				flag = 1;
			}
		}
	}
 	if (flag == 1)
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}
}
//function to permutate in order to get Magic square

void permuteSquare(MagSquare_PTR x)
{
	srand(time(NULL));//seed the random number generator 
	
	int i,j,k,m,temp;
	i = rand() % 2;
	j = rand() % 2;
	k = rand() % 2;
	m = rand() % 2;

	temp = *x[i][j];
	*x[i][j] = *x[k][m];
	*x[k][m] =temp;
}
// to generate random function
int Random (int magicsquaresize,int a[])
{
	//srand(time(NULL));//seed the random number generator 
	int n= rand()%(magicsquaresize*magicsquaresize);
    if (a[n]==0)
    {
	  a[n]=-1;
	  return(n+1);
	  //printf("%d\n",n );
	  //printf("Different\n" );
    }
    else if(a[n]==-1)
    {
    	Random (magicsquaresize,a);
    	//printf("calling function again\n");
    }
    //printf("exiting loop" );
    //printf("%d\n",n+1);
   // return (n+1);
}