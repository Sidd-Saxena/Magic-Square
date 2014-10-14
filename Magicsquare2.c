//including the user defined library
#include "Magicsquare.h"

//srand(time(NULL));//seed the random number generator 

//function for allocating random numbers to the 2-D array
void initSquare( MagSquare_PTR x, int magicsquaresize )
{
	srand(time(NULL));//seed the random number generator 
	int m,i,j;
    //initilizing the array for random number generation
	int a[magicsquaresize*magicsquaresize];
	//loop for initializing an array for creating random nos
	for (m=0; m<(magicsquaresize*magicsquaresize); m++)
	{
		a[m]=0;
	}
	/**x[0][0]=16;
	*x[0][1]=3;
	*x[0][2]=2;
    *x[0][3]=13;
	*x[1][0]=5;
	*x[1][1]=10;
	*x[1][2]=11;
    *x[1][3]=8;
	*x[2][0]=9;
	*x[2][1]=6;
	*x[2][2]=7;
    *x[2][3]=4;
	*x[3][0]=12;
	*x[3][1]=15;
	*x[3][2]=14;
	*x[3][3]=1;*/
	//for loop to initialize the matrix with random nos
     for(i=0; i < magicsquaresize; i++)
      {
         for(j=0; j < magicsquaresize; j++) 
  		  {
  		  	//calling the random function to enter into the matrix
  		  		*x[i][j]=Random(magicsquaresize,a);		  				   	
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
	//diagonal for top left to bottom right
	if(diagonal==0)
	{
		for (i = 0; i < magicsquaresize; i++)
		{
			sum = sum + *x[i][i];
		}
	}
//diagonal for top right to bottom left
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
// function to check if the square is magic or not
int isMagic(MagSquare_PTR x, int magicsquaresize )
{
	int n = ((magicsquaresize * ((magicsquaresize*magicsquaresize)+1)))/2;
	//printf("%d\n",n );
	int i=0;
	int flag_cols,flag_row,flag_diag = 0;
	for (i = 0 ;i < magicsquaresize ; i++)
	{
		if (n == sumColumn( i, x, magicsquaresize ))
		{
			//printf("Coloum passed\n");
			flag_cols = 1;
		} 
		if (n != sumColumn( i, x, magicsquaresize ))
		{
			flag_cols = 0;
			//printf("Coloumn failed\n");
			break;
		}
	}
	for (i = 0 ;i < magicsquaresize ; i++)
	{
		if (n == sumRow( i, x, magicsquaresize))
		{
			flag_row = 1;
			//printf("row passed\n");
		}
		if (n != sumRow( i, x, magicsquaresize ))
		{
			flag_row=0;
			//printf("Row failed\n");
			break;
		}
	}
	for (i= 0 ;i < 2; i++)
	{
		if (n == sumDiagonal( i, x, magicsquaresize))
		{
			flag_diag = 1;
			//printf("Diagonal passed\n");
		}
		if (n != sumDiagonal( i, x, magicsquaresize ))
		{
				flag_diag=0;
				//printf("Diagonal failed\n");
				break;
		}
	}
 	if (flag_diag == 1 && flag_row == 1 && flag_cols == 1)
 	{
 		return 1;
 	}
 	else
 	{
 		return 0;
 	}
}

//function to permutate in order to get Magic square
void permuteSquare(MagSquare_PTR x, int magicsquaresize )
{
	//srand(time(NULL));//seed the random number generator 
	//time_t t;
	//srand((unsigned)time(&t));
	int n =magicsquaresize;
	int i,j,k,m,temp;
	do{
	i = rand() % n;
	j = rand() % n;
	k = rand() % n;
	m = rand() % n;
	}while(i==k && j==m);
 /*printf("%d  ",i);
 printf("%d  ",j);
 printf("%d  ",k);
 printf("%d\n",m);*/

	temp = *x[i][j];
	*x[i][j] = *x[k][m];
	*x[k][m] =temp;
}
// to generate random function
int Random (int magicsquaresize,int a[])
{
	int n= rand()%(magicsquaresize*magicsquaresize);
	int returnv;
	//check wheather the number is repeated or not
    if (a[n]==0)//not repeated
    {
	  a[n]=-1;//change the flag
	  returnv=n+1;
	  //return(n+1);//return the value
    }
    else if(a[n]==-1)//repeated
    {
    	//call the function again
    	returnv = Random (magicsquaresize,a);
    
    }
    return returnv;//return the vaue
 }

