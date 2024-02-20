#include sort.h"

/**
 * bubble_sort - A function that sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array of integers to sort
 * @size: The size of the array of integers
 * Return: Nothing!
 * This program conforms to the Betty documentation style
 **/

void bubble_sort(int *array, size_t size)
{
	size_t a, b, max;
	int aux, swapped;

	if (!array || size < 2)
	return;

	max = size - 1;
	swapped = 1;

	while (swapped)
{
	swapped = 0;
	for (a = 0; a < max; ++a)
{
	if (array[a] > array[a + 1])
{
	aux = array[a];
	array[a] = array[a + 1];
	array[a + 1] = aux;
	swapped = 1;
	print_array(array, size);
}
}
	if (swapped == 1)
	--max;
}
}
