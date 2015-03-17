#ifndef HEADER_H
#define HEADER_H
 
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std;

/*-------VARIABLES THE USER CAN ALTER-------*/
const int MAX_ARRAY_SIZE = 200; // will be one smaller 
/*------------------------------------------*/


/* Other Functions */
void nullArray(int generateArray[]);
void generateRandomNumbers(int generateArray[], int arraySize);
void printOut(int numberArray[MAX_ARRAY_SIZE]);
void copyArray(int primaryArray[], int copiedArray[]);

/* Sorting Functions */
void insertionSort(int arr[], int length);
void mergeSortCaller(int a[], int low, int high);
void mergeSort(int a[], int low, int high);
void quickSortCaller(int a[], int first, int last);
void quickSort(int a[], int first, int last);
int pivot(int a[], int first, int last);
void swap(int& a, int& b);
void swapNoTemp(int& a, int& b);
void print(int a[], const int& N);
void quickInsertionSortCaller(int a[], int first, int last, int k);
void quickInsertionSort(int a[], int first, int last, int kElements);
void insertionSortForQuick(int arr[], int length);

#endif