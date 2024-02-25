#ifndef DECK_H
#define DECK_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 **/

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void sort_deck(deck_node_t **deck);
size_t list_len_deck(deck_node_t *list);
int _strcmp(const char *s1, const char *s2);
int card_value(deck_node_t *node);

#endif /* DECK_H */
