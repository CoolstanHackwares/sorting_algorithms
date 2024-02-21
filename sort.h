#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#define INCREMENT 1
#define DECREMENT -1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *, size_t);
void print_list(const listint_t *);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
size_t list_len(listint_t *list);
void swap_nodes(listint_t **list, listint_t *node);
listint_t *get_dlistint_lelem(listint_t *h);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void heap_sort(int *array, size_t size);
void heapify(int *array, int heap_size, int root_index, int size);
void radix_sort(int *array, size_t size);
void count_sort_LSD(int *array, size_t size, size_t lsd);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
