#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		prev = current->prev;

		while (prev != NULL && prev->n > key->n)
		{
			/* Swap key and prev nodes */
			if (key->next != NULL)
				key->next->prev = prev;
			prev->next = key->next;
			key->prev = prev->prev;

			if (prev->prev != NULL)
				prev->prev->next = key;
			else
				*list = key;

			prev->prev = key;
			key->next = prev;

			prev = key->prev;

			/* Print the list after swapping */
			print_list(*list);
		}

		current = current->next;
	}
}
