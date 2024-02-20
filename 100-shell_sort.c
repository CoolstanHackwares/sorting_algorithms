#include "sort.h"

/**
 * shell_sort - A function that sorts an array of integers in ascending order
 * using Shell sort algorithm with the Knuth sequence
 * @array: The array of integers to sort
 * @size: The size of the array
 * This program conforms to the betty documentation style
 **/

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, a, b;
	int temp;

	if (!array || size < 2)
	return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
{
	for (a = gap; a < size; a++)
{
	temp = array[a];

	for (b = a; b >= gap && array[b - gap] > temp; b -= gap)
{
	array[b] = array[b - gap];
}

	array[b] = temp;
}

	print_array(array, size);
}
}
