#include "sort.h"

/**
 * swap - swap two value
 * @a: first value
 * @b: second value
*/

void swap(int *a, int *b)
{
	int temp = *a;
	(*a) = (*b);
	(*b) = temp;
}

/**
 * partition - works on the subarray
 * @low: left index of a an array
 * @high: right index of an array
 * @size: array's size
 * @arr: a pointer to the subarray
 * Return: pivot's index
*/

int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
			print_array(arr, size);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}

/**
 * quickSort - sort an array
 * @arr: a pointer to the array to be sorted
 * @low: left index
 * @high: right index
 * @size: array's size
 * ]size: array's size
*/

void quickSort(int *arr, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(arr, low, high, size);
		quickSort(arr, low, pivot_index - 1, size);
		quickSort(arr, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: a pointer to the array to be sorted
 * @size: array's size0
*/

void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quickSort(array, 0, size - 1, size);
}
