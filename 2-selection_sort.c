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
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: a pointer to the array to be sorted
 * @size: array's size
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			swap(array + i, array + min);
			print_array(array, size);
		}
	}
}
