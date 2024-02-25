#include "deck.h"

/**
 * sort_deck - A function that sorts a deck of cards in ascending order.
 * @deck: A doubly linked list representing the deck of cards
 * This program conforms to the betty documentation style
 **/

void sort_deck(deck_node_t **deck)
{
	deck_node_t *curr;
	size_t len;
	deck_node_t *one, *two, *three, *four;

	len = list_len_deck(*deck);

	if (!deck || !*deck || len < 2)
		return;

	curr = *deck;
	while (curr)
	{
		if (curr->prev && card_value(curr) < card_value(curr->prev))
		{
			one = curr->prev->prev;
			two = curr->prev;
			three = curr;
			four = curr->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			curr = *deck;
			continue;
		}
		else
			curr = curr->next;
	}
}

/**
 * card_value - A function that calculates the value of a card in the deck.
 * @node: The deck node representing the card.
 *
 * Return: The calculated value of the card.
 * This program conforms to the betty documentation style
 **/

int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "9", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i, kind_val = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!_strcmp(node->card->value, val[i - 1]))
			kind_val = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!_strcmp(kinds[node->card->kind], kinds[i - 1]))
			kind_val = kind_val + (13 * i);
	}

	return (kind_val);
}

/**
 * _strcmp - A function that compares two strings.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: Less than 0 if s1 is less than s2, 0 if they're equal,
 * more than 0 if s1 is greater than s2.
 * This program conforms to the betty documentation style
 **/

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - A function that returns the length of a deck represented
 * as a linked list.
 * @list: The head of the linked list.
 *
 * Return: The length of the linked list.
 * This program conforms to the betty documentation style
 **/
size_t list_len_deck(deck_node_t *list)
{
	size_t len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}
