#include "sort.h"

/**
 * counting_sort - A function that sorts an  array of integers in ascending
 * order using the counting sort algorithm
 * @array: The array to sort
 * @size: The size of array
 *
 * Return: nothing
 * This program conforms to the betty documentation style
 **/

void counting_sort(int *array, size_t size)
{
	int max = 0, a = 1;
	int *count = NULL, *arr_tmp = NULL;

	if (!array || size < 2)
		return;
	max = array[0];
	while (a < (int) size)
	{
		if (array[a] > max)
			max = array[a];
		a++;
	}
	arr_tmp = malloc(sizeof(int) * size);
	if (!arr_tmp)
		return;
	count = malloc(sizeof(int) * max + 1);
	if (!count)
	{
		free(arr_tmp);
		return;
	}

	for (a = 0; a <= max; ++a)
		count[a] = 0;
	for (a = 0; a < (int) size; ++a)
		count[array[a]]++;
	for (a = 1; a <= max; ++a)
		count[a] = count[a - 1] + count[a];
	print_array(count, max + 1);
	for (a = 0; a < (int) size; ++a)
	{
		arr_tmp[count[array[a]] - 1] = array[a];
		count[array[a]]--;
	}
	for (a = 0; a < (int) size; ++a)
		array[a] = arr_tmp[a];

	free(count);
	free(arr_tmp);
	count = arr_tmp = NULL;
}
