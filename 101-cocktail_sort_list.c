#include "sort.h"

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 * @list: A pointer to a pointer to the head of the doubly linked list
 * This program conforms to the betty documentation style
 **/

void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || list_len(*list) < 2)
	return;

	p = *list;
	while (!sorted)
{
	sorted = 1;
	while (p->next)
{
	if (p->n > p->next->n)
{
	sorted = 0;
	swap_nodes(list, &p, &(p->next));
	print_list(*list);
}
	else
	p = p->next;
}
	if (sorted)
	break;
	p = p->prev;
	while (p->prev)
{
	if (p->n < p->prev->n)
{
	sorted = 0;
	p = p->prev;
	swap_nodes(list, &(p->prev), &p);
	print_list(*list);
}
	else
	p = p->prev;
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
	listint_t *one, *two, *three, *four;

	one = (*n1)->prev;
	two = *n1;
	three = *n2;
	four = (*n2)->next;

	two->next = four;
	if (four)
	four->prev = two;

	three->next = two;
	three->prev = one;
	if (one)
	one->next = three;
	else
	*list = three;

	two->prev = three;

	if (four)
	four->prev = two;
}
