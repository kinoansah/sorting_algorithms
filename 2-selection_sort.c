#include "sort.h"
#include <stdio.h>

/**
 * swap - changes positions of two elements
 *
 * This function takes two pointers to integers (int *a and int *b) as input
 * and swaps the values they point to.
 *
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * Selection sort.
 *
 * This function implements the Selection sort algorithm to sort the given
 * array in ascending order.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)

		{
			if (array[j] < array[min_idx])
			{min_idx = j; }
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
