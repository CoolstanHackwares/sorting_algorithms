#include "sort.h"

/**
 * merge - A function that merges two sub-arrays of array[].
 * @array: The array to be sorted
 * @temp: Temporary array for merging
 * @left: Index of the left sub-array
 * @mid: Index of the middle element
 * @right: Index of the right sub-array
 * This program conforms to the betty documentation style
 **/

void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i, j, k;

	printf("[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	i = left;
	j = mid;
	k = 0;

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];

	while (j < right)
		temp[k++] = array[j++];

	for (i = 0, k = left; k < right;)
		array[k++] = temp[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - A function that recursively sorts an array using the
 * Merge sort algorithm
 * @array: The array to be sorted
 * @temp: Temporary array for merging
 * @left: Index of the leftmost element
 * @right: Index of the rightmost element
 * This program conforms to the betty documentation style
 **/

void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
	if (right - left <= 1)
		return;

	size_t mid = left + (right - left) / 2;

	merge_sort_recursive(array, temp, left, mid);
	merge_sort_recursive(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - A function that sorts an array of integers in ascending order
 * using Merge sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 * This program conforms to the betty documentation style
 **/

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	merge_sort_recursive(array, temp, 0, size);

	free(temp);
}
