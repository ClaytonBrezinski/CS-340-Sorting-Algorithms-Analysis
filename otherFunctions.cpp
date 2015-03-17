#ifndef OTHERFUNCTIONS_CPP
#define OTHERFUNCTIONS_CPP
#include "Header.h"
 
void nullArray(int generateArray[])
{
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		generateArray[i] = NULL;
	}
}

void copyArray(int primaryArray[], int copiedArray[])
{
	for (int i = 0; i < MAX_ARRAY_SIZE; i++)
	{
		copiedArray[i] = primaryArray[i];
	}
}

void generateRandomNumbers(int generateArray[], int arraySize)
{

	nullArray(generateArray);
	for (int i = 0; i < arraySize; i++)
	{
		generateArray[i] = (rand() % 100) + 1; // %100 is the max, 1 is the minimum
	}
}

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