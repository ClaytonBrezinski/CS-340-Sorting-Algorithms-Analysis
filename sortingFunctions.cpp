/*
student name : Clayton Brezinski
student # : 200220989
assignment number : Assignment 3
date written : March 17th, 2015
*/


#ifndef SORTINGFUNCTIONS_CPP
#define SORTINGFUNCTIONS_CPP
#include "Header.h"

/*Insertion Sort function*/
void insertionSort(int arr[], int length)
{
	cout << "Insertion Sort -- " << endl;
	//
	clock_t start = clock();	// begin timer
	int j, temp;
	for (int i = 0; i < length; i++)// may have to change i=#
	{
		j = i;

		while (j > 0 && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}

	clock_t timeElapsed = clock() - start;
	unsigned msElapsed = timeElapsed / (CLOCKS_PER_SEC / 1000);
	cout << "the time to complete this algorithm was : " << msElapsed << "ms "<< endl;

	// printOut(arr);
}

/*Quick Sort functions*/
void quickSortCaller(int a[], int first, int last)
{
	cout << "Quick Sort -- " << endl;
	clock_t start = clock();	// begin timer

	quickSort(a, first, last);

	clock_t timeElapsed = clock() - start;
	unsigned msElapsed = timeElapsed / (CLOCKS_PER_SEC / 1000);
	cout << "the time to complete this algorithm was : " << msElapsed << "ms " << endl;

	// prep array for print out then print
	int j = 1;
	for (int i = 0; i < last; i++)
	{
		if (a[i] == NULL && a[j] != NULL)
		{
			a[i] = a[j];
			a[j] = NULL;
		}
		j++;
	}
	// printOut(a);
}
void quickSort(int a[], int first, int last)
{
	int pivotElement;

	if (first < last)
	{
		pivotElement = pivot(a, first, last);
		quickSort(a, first, pivotElement - 1);
		quickSort(a, pivotElement + 1, last);
	}
}
int pivot(int a[], int first, int last)
{
	int  p = first;
	int pivotElement = a[first];

	for (int i = first + 1; i <= last; i++)
	{
		/* If you want to sort the list in the other order, change "<=" to ">" */
		if (a[i] <= pivotElement)
		{
			p++;
			swap(a[i], a[p]);
		}
	}

	swap(a[p], a[first]);

	return p;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
void swapNoTemp(int& a, int& b)
{
	a -= b;
	b += a;// b gets the original value of a
	a = (b - a);// a gets the original value of b
}
void print(int a[], const int& N)
{
	for (int i = 0; i < N; i++)
		cout << "array[" << i << "] = " << a[i] << endl;
}

/* Merge Sort functions*/
void mergeSortCaller(int a[], int low, int high)
{
	cout << "Merge Sort -- " << endl;
	clock_t start = clock();	// begin timer

	mergeSort(a, low, high);
	
	clock_t timeElapsed = clock() - start;
	unsigned msElapsed = timeElapsed / (CLOCKS_PER_SEC / 1000);
	cout << "the time to complete this algorithm was : " << msElapsed << "ms " << endl;

	// prep array for print then print
	int j = 1;
	for (int i = 0; i < high; i++)
	{

		if (a[i] == NULL && a[j] != NULL)
		{
			a[i] = a[j];
			a[j] = NULL;
		}
		j++;
	}
	// printOut(a);
}
void merge(int *a, int low, int high, int mid);
void mergeSort(int a[], int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		mergeSort(a, low, mid);
		mergeSort(a, mid + 1, high);
		merge(a, low, high, mid);
	}
	return;
}
void merge(int a[], int low, int high, int mid)
{
	int i, j, k, c[MAX_ARRAY_SIZE];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = a[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++)
	{
		a[i] = c[i];
	}
}

/*Quick Insertion Sort functions*/
void quickInsertionSortCaller(int a[], int first, int last, int k)
{
	cout << "Quick Insertion Sort -- " << endl;
	clock_t start = clock();		// begin timer

	quickInsertionSort(a, first, last, k);

	// prep array for insertion sort (included in timing due to it being necessary to pass to insertion sort
	int j = 1;
	for (int i = 0; i < last; i++)
	{

		if (a[i] == NULL && a[j] != NULL)
		{
			a[i] = a[j];
			a[j] = NULL;
		}
		j++;
	}
	insertionSortForQuick(a, last);

	clock_t timeElapsed = clock() - start;
	unsigned msElapsed = timeElapsed / (CLOCKS_PER_SEC / 1000);
	cout << "the time to complete this algorithm was : " << msElapsed << "ms " << endl;
	// printOut(a);

}
void quickInsertionSort(int a[], int first, int last,int kElement )
{
	int pivotElement;
	int subArraySize = last - first;
	if (first < last && subArraySize > kElement)
	{
		pivotElement = pivot(a, first, last);
		quickInsertionSort(a, first, pivotElement - 1, kElement);
		quickInsertionSort(a, pivotElement + 1, last, kElement);
	}
	else
	{
		return;
	}
}
void insertionSortForQuick(int arr[], int length)
{
	int j, temp;
	for (int i = 0; i < length; i++)
	{
		j = i;

		while (j > 0 && arr[j] < arr[j - 1])
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
#endif
 