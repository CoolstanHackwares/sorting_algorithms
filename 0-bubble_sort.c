#include sort.h"

/**
  * bubble_sort - A function that sorts an array of integers in ascending order
  * using the Bubble sort algorithm.
  * @array: The array of integers to sort
  * @size: The size of the array of integers
  *
  * Return: Nothing!
  * This program conforms to the Betty documentation style
  **/

void bubble_sort(int *array, size_t size)
{
	int a, b, temp;
	int swapped;

	for (a = 0; a < size - 1; a++)
{
	swapped = 0;

	for (b = 0; b < size - a - 1; b++)
{
	if (array[b] > array[b + 1])
{
	temp = array[b];
	array[b] = array[b + 1];
	array[b + 1] = temp;

	swapped = 1;
}
}

	if (!swapped)
{
	break;
}
}
}
