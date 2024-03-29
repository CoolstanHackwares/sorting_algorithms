#include "sort.h"

/**
 * swap - A function that swaps two elements in an array
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 * This program conforms to the betty documentation style
 **/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - A function that partitions an array using the Hoare scheme
 * @array: Array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 *
 * Return: Index of the pivot after partitioning
 * This program conforms to the betty documentation style
 **/

int hoare_partition(int *array, int low, int high)
{
	int pivot = array[low];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
	}
}

/**
 * quick_sort_hoare_recursive - Recursively sorts a partition of an array
 * using quick sort with horare partition scheme
 * @array: Array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * This program conforms to the betty documentation style
 **/

void quick_sort_hoare_recursive(int *array, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high);

		quick_sort_hoare_recursive(array, low, pivot);
		quick_sort_hoare_recursive(array, pivot + 1, high);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: Array to be sorted
 * @size: Size of the array
 * This program conforms to the betty documentation style
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, 0, size - 1);
}
