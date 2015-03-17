#ifndef SORTINGFUNCTIONS_CPP
#define SORTINGFUNCTIONS_CPP
#include "Header.h"

void insertionSort(int arr[], int length)
{
	cout << "Insertion Sort -- " << endl;
	//
	auto t1 = std::chrono::high_resolution_clock::now();
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
	//
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "f() took " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << " milliseconds\n";

	printOut(arr);
}


void quickSortCaller(int a[], int first, int last)
{
	cout << "Quick Sort -- " << endl;
	clock_t start = clock();

	quickSort(a, first, last);

	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	cout << "the time to complete this algorithm was : " << time << endl;

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
	printOut(a);
}
/**
* Quicksort.
* @param a - The array to be sorted.
* @param first - The start of the sequence to be sorted.
* @param last - The end of the sequence to be sorted.
*/
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

/**
* Find and return the index of pivot element.
* @param a - The array.
* @param first - The start of the sequence.
* @param last - The end of the sequence.
* @return - the pivot element
*/
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


/**
* Swap the parameters.
* @param a - The first parameter.
* @param b - The second parameter.
*/
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

/**
* Swap the parameters without a temp variable.
* Warning! Prone to overflow/underflow.
* @param a - The first parameter.
* @param b - The second parameter.
*/
void swapNoTemp(int& a, int& b)
{
	a -= b;
	b += a;// b gets the original value of a
	a = (b - a);// a gets the original value of b
}

/**
* Print an array.
* @param a - The array.
* @param N - The size of the array.
*/
void print(int a[], const int& N)
{
	for (int i = 0; i < N; i++)
		cout << "array[" << i << "] = " << a[i] << endl;
}


void mergeSortCaller(int a[], int low, int high)
{
	cout << "Merge Sort -- " << endl;
	clock_t start = clock();

	mergeSort(a, low, high);
	
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	cout << "the time to complete this algorithm was : " << time << endl;

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
	printOut(a);
}
void merge(int a[], int, int, int);

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
	int i, j, k, c[50];
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

void quickInsertionSortCaller(int a[], int first, int last, int k)
{
	cout << "Quick Insertion Sort -- " << endl;
	clock_t start = clock();

	quickInsertionSort(a, first, last, k);

	// prep array for insertion sort
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

	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC * 1000.0;
	cout << "the time to complete this algorithm was : " << time << endl;
	printOut(a);

}
void quickInsertionSort(int a[], int first, int last,int kElement )
{
	int pivotElement;
	int subArraySize = last - first;
	if (first < last && subArraySize > kElement)
	{
		pivotElement = pivot(a, first, last);
		quickSort(a, first, pivotElement - 1);
		quickSort(a, pivotElement + 1, last);
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
 