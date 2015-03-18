/*
student name : Clayton Brezinski
student # : 200220989
assignment number : Assignment 3
date written : March 17th, 2015
*/


#ifndef MAIN_CPP
#define MAIN_CPP 

#include "Header.h"

void printOut(int numberArray[MAX_ARRAY_SIZE]);
int main()
{
	int primaryNumberArray[MAX_ARRAY_SIZE];
	int tempSortArray[MAX_ARRAY_SIZE];
	int arraySize = -5;
	int k;

	/* User input Section - User enters size of array and k value for quick insertion*/
	while (arraySize >= MAX_ARRAY_SIZE || arraySize < 0)
	{
		cout << "The max amount of numbers you can use is " << MAX_ARRAY_SIZE - 1 << " Please enter how many numbers you will be using:" << endl;
		cin >> arraySize;
	}
	cout << "Please enter the k value for quick-insertion" << endl;
	cin >> k;

	srand(time(NULL)); // generate random numbers

	// Create the array of random numbers and print the array out to show that it is randomn
	generateRandomNumbers(primaryNumberArray, arraySize);
	// printOut(primaryNumberArray);

	// make the tempSortArray the same as the primaryNumberArray, then sort the temp array using insertion sort
	copyArray(primaryNumberArray, tempSortArray);
	insertionSort(tempSortArray, arraySize);

	// reset the tempSortArray and use quick sort
	copyArray(primaryNumberArray, tempSortArray);
	quickSortCaller(tempSortArray, 0, arraySize); 

	// reset the tempSortArray and use merge sort
	copyArray(primaryNumberArray, tempSortArray);
	mergeSortCaller(tempSortArray, 0, arraySize);

	// reset the tempSortArray and use quick-insertion sort
	copyArray(primaryNumberArray, tempSortArray);
	quickInsertionSortCaller(tempSortArray, 0, arraySize, k);

	//nullify the array and exit 
	nullArray(primaryNumberArray);	
	char temp;
	cout << endl << "please press any key to continue ... " << endl;
	cin >> temp;
}
#endif