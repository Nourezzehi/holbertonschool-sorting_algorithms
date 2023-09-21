#include "sort.h"

/**
 * swap_print - swap two value
 * @a: first value
 * @b: second value
 * @array: a pointer to the array to print
 * @size: array's size
*/

void swap_print(int *array, int *a, int *b, size_t size)
{
	int temp = *a;
	(*a) = (*b);
	(*b) = temp;
	print_array(array, size);
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
	int pivot = arr[high], i = low, j;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			if (i != j)
				swap_print(arr, &arr[j], &arr[i], size);
			i++;
		}
	}
	if (i != high)
		swap_print(arr, &arr[high], &arr[i], size);
	return (i);
}

/**
 * quickSort - sort an array
 * @arr: a pointer to the array to be sorted
 * @low: left index
 * @high: right index
 * @size: array's size
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
