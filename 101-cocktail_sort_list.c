#include "sort.h"

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 * @list: A pointer to a pointer to the head of the doubly linked list
 * This program conforms to the betty documentation style
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int sorted = 0;

	if (!list || !(*list) || !(*list)->next)
	return;

	while (!sorted)
{
	sorted = 1;
	for (current = *list; current->next != NULL; current = current->next)
{
	if (current->n > current->next->n)
{
	swap_nodes(list, &current, &current->next);
	print_list(*list);
	sorted = 0;
}
}

	if (sorted)
	break;

	sorted = 1;
	for (; current->prev != NULL; current = current->prev)
{
	if (current->n < current->prev->n)
{
	swap_nodes(list, &current->prev, &current);
	print_list(*list);
	sorted = 0;
}
}
}
}

/**
 * swap_nodes - A function that swaps two nodes in a doubly linked list
 * @list: A pointer to a pointer to the head of the doubly linked list
 * @n1: The pointer to the first node to swap
 * @n2: The pointer to the second node to swap
 * This program conforms to the betty documentation style
 **/

void swap_nodes(listint_t **list, listint_t **n1, listint_t **n2)
{
	listint_t *temp;

	temp = (*n1)->prev;
	(*n1)->prev = (*n2);
	(*n2)->prev = temp;

	if (temp)
	temp->next = (*n2);

	temp = (*n2)->next;
	(*n2)->next = (*n1);
	(*n1)->next = temp;

	if (temp)
	temp->prev = (*n1);

	if (!(*n1)->prev)
	*list = *n1;
}
