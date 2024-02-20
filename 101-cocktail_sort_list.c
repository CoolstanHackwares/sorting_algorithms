#include "sort.h"

/**
 * list_len - A function returns the length of a list
 * @list: The head of the list
 *
 * Return: length of the list
 * This program conforms to the betty documentation style
 **/

size_t list_len(listint_t *list)
{
	size_t len = 0;

	while (list)
{
	len++;
	list = list->next;
}
	return (len);
}

/**
 * switch_nodes - A function that swaps two nodes in a doubly linked list
 * @list: A double pointer to the head of the doubly linked list
 * @p: The pointer to node
 * This program conforms to the betty documentation style
 **/

void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 * cocktail_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail Shaker Sort algorithm.
 * @list: A double pointer to the head of the doubly linked list
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
				switch_nodes(list, &p);
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
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
