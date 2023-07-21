#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps the values of two integers.
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
 * lomuto_partition - Lomuto partition scheme for Quich sort.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Index of the partion pivot after rearrangement.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: Void (No explicit return).
 */
void quick_sort_recursive(int *array, int low, int high)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high);

		print_array(array, high + 1);

		quick_sort_recursive(array, low, pi - 1);
		quick_sort_recursive(array, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 *
 * Return: Void (No exlicit return).
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}
