#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list
 * This program conforms to the betty documentation style
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *prev;

	if (!list || !(*list) || !(*list)->next) 
	return;

	for(current = (*list)->next; current; current = current->next)
{
	prev = current->prev;
	while(prev && current->n < prev->n)
{
	if(prev->prev)
	prev->prev->next = current;
	else 
	*list = current;

	current->prev = prev->prev;
	prev->prev = current;
	current->next = prev;

	print_list(*list);

	current = prev;
	prev = current->prev;
}
}
}
