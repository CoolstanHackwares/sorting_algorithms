#include "sort.h"

/**
 * quick_sort - A function that sorts an array of integers in ascending order
 * using the Quick sort algorithm with Lomuto partition scheme.
 * @array: The array of integers to sort
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - A recursive helper function for Quick sort
 * @array: The array of integers to sort
 * @low: The starting index of the partition to sort
 * @high: The ending index of the partition to sort
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
{
	pivot_index = lomuto_partition(array, low, high, size);
	quicksort_recursive(array, low, pivot_index - 1, size);
	quicksort_recursive(array, pivot_index + 1, high, size);
}
}

/**
 * lomuto_partition - The Lomuto partition scheme for Quick sort
 * @array: The array of integers to partition
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partition
 * This program conforms to the betty documentation style
 **/

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = 0, a = 0, b = 0, temp = 0;

	pivot = array[high];
	a = low;

	for (b = low; b < high; ++b)
{
	if (array[b] < pivot)
{
	/* Swap the elements */
	temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	if (temp != array[a])
	/* Print the array after each swap */
	print_array(array, size);

	++a;
}
}
	temp = array[a];
	array[a] = array[high];
	array[high] = temp;

	if (temp != array[a])
	print_array(array, size);

	return (a);
}
