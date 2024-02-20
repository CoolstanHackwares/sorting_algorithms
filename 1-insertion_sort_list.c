#include "sort.h"

/**
 * insertion_sort_list - A function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list
 * This program conforms to the betty documentation style
 **/

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

	listint_t *current = (*list)->next;

	while (current != NULL)
{
	listint_t *temp = current;

	while (temp->prev != NULL && temp->n < temp->prev->n)
{
	/* Swap the nodes */
	if (temp->next != NULL)
	temp->next->prev = temp->prev;

	temp->prev->next = temp->next;
	temp->next = temp->prev;
	temp->prev = temp->prev->prev;

	if (temp->prev != NULL)
	temp->prev->next = temp;
	else
	*list = temp;

	/* Print the list after each swap */
	print_list(*list);
}
	current = current->next;
}
}
