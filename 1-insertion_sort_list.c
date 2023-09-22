#include "sort.h"

/**
 * insertion_sort_list  - a doubly linked list of integers in ascending order
 * using the Insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node, *prev;

	if (!list || !(*list) || !((*list)->next))
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		node = current;
		prev = current->prev;

		while (prev && (node->n < prev->n))
		{
			if (node->next != NULL)
				node->next->prev = prev;
			prev->next = node->next;
			node->prev = prev->prev;
			prev->prev = node;
			node->next = prev;

			if (node->prev != NULL)
				node->prev->next = node;
			else
				*list = node;

			prev = node->prev;
			print_list(*list);
		}

		current = current->next;
	}
}
