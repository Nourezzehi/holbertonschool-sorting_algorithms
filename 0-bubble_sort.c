#include "sort.h"

/**
 * swap - swap two value
 * @a: first value
 * @b: second value
*/

void swap(int *a, int *b)
{
	(*a) = (*a) + (*b);
	(*b) = (*a) - (*b);
	(*a) = (*a) - (*b);
}

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: the array to be sortes
 * @size: array's size
*/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (*(array + j) > *(array + j + 1))
			{
				swap(array + j, array + j + 1);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
