#include "sort.h"

/**
 * swap_integer - A function that swaps indexes of a given array
 * @l: The left or low index to swap
 * @r: The right or high index
 * This program conforms to the betty documentation style
 **/

void swap_integer(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/*
 * bitonic_sort - A function that sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * This program conforms to the betty documentation style
 **/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	return;
	bit_sort_rec(array, 0, size, 1, size);
}

/**
 * bitonic_merge - A function that merges two subarrays in a Bitonic manner.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray to be merged.
 * @count: Size of the subarray to be merged.
 * @dir: 1 if merging in ascending order, 0 if descendin
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void bitonic_merge(int *array, int low, int count, int dir, size_t size)
{
	int i, k;

	if (count > 1)
{
	k = count / 2;

	for (i = low; i < low + k; i++)
{
	if (((array[i] > array[i + k]) && dir == 1) ||
	(dir == 0 && (array[i] < array[i + k])))
	swap_integer(&array[i], &array[i + k]);
}
	/* Recursively merge two halves */
	bitonic_merge(array, low, k, dir, size);
	bitonic_merge(array, low + k, k, dir, size);
}
}

/**
 * bit_sort_rec - A function that recursively applies Bitonic sort.
 * @array: The array to be sorted.
 * @low: Starting index of the subarray to be sorted.
 * @count: Size of the subarray to be sorted.
 * @dir: 1 if sorting in ascending order, 0 if descending
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void bit_sort_rec(int *array, int low, int count, int dir, size_t size)
{
	int k;

	if (count > 1)
{
	k = count / 2;
	printf("Merging [%lu/%lu] ", count, (int)size);
	if (dir == 1)
		printf("(UP):\n");
	else
		printf("(DOWN):\n");
	print_array(array + low, count);
	bit_sort_rec(array, low, k, 1, size);
	bit_sort_rec(array, low + k, k, 0, size);
	bitonic_merge(array, low, count, dir, size);
	printf("Result [%lu/%lu] ", count, (int)size);
	if (dir == 1)
	printf("(UP):\n");
	else
	printf("(DOWN):\n");
	print_array(array + low, count);
}
}
