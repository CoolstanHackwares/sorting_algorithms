#include "sort.h"

/**
 * swap - A function that swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 * This program conforms to the betty documentation style
 **/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * quick_sort_hoare_recursive - recursively sorts a partition of an array
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: array to be sorted
 * @size: size of the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 * This program conforms to the betty documentation style
 **/

void quick_sort_hoare_recursive(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot = hoare_partition(array, size, low, high);

		printf("Partition: ");
		print_array(array + low, high - low + 1);

		quick_sort_hoare_recursive(array, size, low, pivot);
		quick_sort_hoare_recursive(array, size, pivot + 1, high);
	}
}

/**
 * hoare_partition - partitions the array using Hoare scheme
 * @array: array to be partitioned
 * @size: size of the array
 * @low: starting index of the partition
 * @high: ending index of the partition
 *
 * Return: index of the pivot after partitioning
 * This program conforms to the betty documentation style
 **/

int hoare_partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
{
	do
{
	i++;
}
	while (array[i] < pivot);

	do
{
	j--;
}
	while (array[j] > pivot);

	if (i >= j)
	return (j);

	swap(array + i, array + j);
	print_array(array, size);
}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * using the Quick sort algorithm with Hoare partition scheme
 * @array: array to be sorted
 * @size: size of the array
 * This program conforms to the betty documentation style
 **/

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, size, 0, size - 1);
}
