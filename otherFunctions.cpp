/*
student name : Clayton Brezinski
student # : 200220989
assignment number : Assignment 3
date written : March 17th, 2015
*/


#ifndef OTHERFUNCTIONS_CPP
#define OTHERFUNCTIONS_CPP
#include "Header.h"
 
/* sets all the variables in the given array to NULL*/
void nullArray(int generateArray[])
{
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		generateArray[i] = NULL;
	}
}

/* makes an exact copy of the primaryArray with the copiedArray*/
void copyArray(int primaryArray[], int copiedArray[])
{
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		copiedArray[i] = primaryArray[i];
	}
}

/*Random number generator*/
void generateRandomNumbers(int generateArray[], int arraySize)
{

	nullArray(generateArray);
	for (int i = 0; i < arraySize; i++)
	{
		generateArray[i] = (rand() % MODNUMBER) + 1; // %100 is the max, 1 is the minimum
	}
}

/*prints out all the variables within the given array*/
void printOut(int numberArray[MAX_ARRAY_SIZE])
{
	cout << "the numbers printed out are:" << endl;
	for (int i = 0; i < MAX_ARRAY_SIZE && numberArray[i] != NULL; i++)
	{
		cout << numberArray[i] << " ";
	}
	cout << endl << endl;
}

#endif