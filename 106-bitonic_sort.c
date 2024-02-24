#include "sort.h"

/**
 * bitonic_sort - A function that sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * This program conforms to the betty documentation style
 **/

void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_merge - A function that merges two subarrays in a Bitonic manner.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray to be merged.
 * @count: Size of the subarray to be merged.
 * @dir: 1 if merging in ascending order, 0 if descending
 * This program conforms to the betty documentation style
 **/

void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	int temp;
	size_t i, k;

	if (count > 1)
{
	k = count / 2;

	for (i = low; i < low + k; i++)
{
	if ((array[i] > array[i + k]) == dir)
{
	/* Swap elements at indices i and i+k */
	temp = array[i];
	array[i] = array[i + k];
	array[i + k] = temp;

	/* Print the array after swapping */
	print_array(array, count);
}
}

	/* Recursively merge two halves */
	bitonic_merge(array, low, k, dir);
	bitonic_merge(array, low + k, k, dir);
}
}

/**
 * bitonic_sort_recursive - A function that recursively applies Bitonic sort.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray to be sorted.
 * @count: Size of the subarray to be sorted.
 * @dir: 1 if sorting in ascending order, 0 if descending
 * This program conforms to the betty documentation style
 **/

void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
{
	k = count / 2;

	/* Sort in ascending order */
	bitonic_sort_recursive(array, low, k, 1);

	/* Sort in descending order */
	bitonic_sort_recursive(array, low + k, k, 0);

	/* Merge the entire sequence in ascending order */
	bitonic_merge(array, low, count, dir);
}
}
