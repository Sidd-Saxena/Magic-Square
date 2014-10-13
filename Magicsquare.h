#ifndef Magicsquare_h
#define Magicsquare_h

//defining all the libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//defining the size of magic box
#define MAGICSIZE 3

// defining new datatype
typedef int MSQUARE_TYPE[MAGICSIZE][MAGICSIZE];
typedef MSQUARE_TYPE *MagSquare_PTR;


//declaring the function
void initSquare( MagSquare_PTR x, int magicsquaresize );
void printSquare( MagSquare_PTR x, int magicsquaresize );
int sumColumn( int column, MagSquare_PTR x, int magicsquaresize );
int sumRow(int row, MagSquare_PTR x, int magicsquaresize);
int sumDiagonal( int diagonal, MagSquare_PTR x, int magicsquaresize );
int isMagic(MagSquare_PTR x, int magicsquaresize );
void permuteSquare(MagSquare_PTR x,int magicsquaresize );
int Random (int magicsquaresize,int a[]);

#endif