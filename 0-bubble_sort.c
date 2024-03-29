#include "sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array of integers to sort
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	if (array == NULL || size < 2)
	return;

	for (i = 0; i < size - 1; i++)
{
	swapped = 0;

	for (j = 0; j < size - 1 - i; j++)
{
	if (array[j] > array[j + 1])
{
	/* Swap elements */
	temp = array[j];
	array[j] = array[j + 1];
	array[j + 1] = temp;

	/* Print the array after each swap */
	print_array(array, size);

	swapped = 1;
}
}
	/* If no two elements were swapped in inner loop, array is sorted */
	if (swapped == 0)
	break;
}
}
