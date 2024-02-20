#include "sort.h"

/**
 * getMax - A function that returns the maximum value in an array
 * @array: Array of integers
 * @size: Size of the array
 * Return: Maximum value in the array
 * This program conforms to the betty documentation style
 **/

int getMax(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - A function that sorts an array based on a
 * significant digit (exp)
 * @array: Array of integers
 * @size: Size of the array
 * @exp: Current significant digit (power of 10)
 * This program conforms to the betty documentation style
 **/

void countSort(int *array, size_t size, int exp)
{
	const int radix = 10;
	int *output = malloc(sizeof(int) * size);
	int count[radix] = {0};

	if (output == NULL)
	{
		fprintf(stderr, "Memory allocation error\n");
		exit(EXIT_FAILURE);
	}

	/* Count occurrences of each digit at the current significant digit */
	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % radix]++;

	/* Calc the cumulative count to determine the position of each element */
	for (int i = 1; i < radix; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % radix] - 1] = array[i];
		count[(array[i] / exp) % radix]--;
	}

	/* Copy the sorted elements back to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	/* Print the current state of the array */
	print_array(array, size);

	/* Free dynamically allocated memory */
	free(output);
}

/**
 * radix_sort - A function that sorts an array of integers in ascending order
 * using Radix sort
 * @array: Array of integers
 * @size: The Size of the array
 * This program conforms to the betty documentation style
 **/

void radix_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int max = getMax(array, size);

	/* Perform counting sort for every digit */
	for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(array, size, exp);
}
