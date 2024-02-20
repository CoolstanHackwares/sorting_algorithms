#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list
 * This program conforms to the betty documentation style
 **/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *previous;
	int flag;

	if (!list || !(*list) || !(*list)->next)
	return;
	current = (*list)->next;

	while (current)
{
	flag = 0;
	temp = current;
	previous = temp->prev;

	while (previous && temp->n < previous->n)
{
	if (previous->prev)
	previous->prev->next = temp;
	else
	*list = temp;

	if (temp->next)
	temp->next->prev = previous;
	previous->next = temp->next;
	temp->prev = previous->prev;
	temp->next = previous;
	previous->prev = temp;

	print_list(*list);

	if (temp->prev)
	previous = temp->prev;
	else
	break;
	flag = 1;
}
	if (flag)
	current = temp;
	else
	current = current->next;
}
}
