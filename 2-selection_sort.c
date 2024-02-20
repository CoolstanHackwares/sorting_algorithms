#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using the Selection sort algorithm.
 * @array: The array of integers to sort
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void selection_sort(int *array, size_t size)
{
	size_t a, b, min_index;
	int temp;

	if (!array || size < 2)
	return;

	for (a = 0; a < size - 1; a++)
{
	min_index = a;

	for (b = a + 1; b < size; b++)
{
	if (array[b] < array[min_index])
	min_index = b;
}
	if (min_index != a)
{
	/* Swap the elements */
	temp = array[a];
	array[a] = array[min_index];
	array[min_index] = temp;

	/* Print the array after each swap */
	print_array(array, size);
}
}
}
