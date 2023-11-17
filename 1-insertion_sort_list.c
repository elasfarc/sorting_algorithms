#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in
 *						 ascending order using the Insertion Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 *		  The function sorts the list in place.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *node_to_sort;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;
	while (current)
	{
		node_to_sort = current;
		current = current->next;
		for (previous = node_to_sort->prev;
			(previous && node_to_sort->n < previous->n);
			previous = node_to_sort->prev)
		{
			previous->next = node_to_sort->next;
			node_to_sort->next ? (node_to_sort->next->prev = previous) : (void *)0;
			node_to_sort->next = previous;

			node_to_sort->prev = previous->prev;
			previous->prev
				? (previous->prev->next = node_to_sort)
				: (*list = node_to_sort);
			previous->prev = node_to_sort;
			print_list(*list);
		}
	}
}
