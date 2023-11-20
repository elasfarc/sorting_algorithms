#include "sort.h"

listint_t *sort_forward(listint_t *, listint_t *, listint_t **, int *);
listint_t *sort_backward(listint_t *, listint_t *, listint_t **, int *);

/**
 * swap - Swap two nodes in a doubly linked list based on the specified mode
 * @a: Pointer to the first node to be swapped
 * @b: Pointer to the second node to be swapped
 * @head: Double pointer to the head of the linked list
 * @mode: Mode indicating the direction of swapping (FORWARD or BACKWARD)
 *
 * Description: This function swaps two nodes in a doubly linked list based
 * on the specified mode.
 * If the mode is FORWARD, it swaps node 'a' with node 'b'.
 * If the mode is BACKWARD, it swaps node 'b' with node 'a'.
 * The function adjusts the pointers of the neighboring nodes accordingly,
 * updates the head if needed.
 * prints the linked list after the swap using the print_list function.
 *
 *
 * Return: void
 */
void swap(listint_t *a, listint_t *b, listint_t **head, MODE mode)
{
	listint_t *current, *next;

	current = (mode == FORWARD) ? a : b;
	next = (mode == FORWARD) ? b : a;
	if (current->n > next->n)
	{
		current->next = next->next;
		next->prev = current->prev;
		current->prev ? current->prev->next = next : (*head = next);
		current->prev = next;
		next->next ? (next->next->prev = current) : (void *)0;
		next->next = current;
		print_list(*head);
	}

}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in
 *						ascending order using the Cocktail Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the doubly linked list.
 *		  The function sorts the list in place.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *forward_stop = NULL, *backward_stop = NULL;
	int is_swap, *is_swap_ptr = &is_swap;
	MODE mode = FORWARD;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;
	*is_swap_ptr = 1;
	while (*is_swap_ptr)
	{
		*is_swap_ptr = 0;
		if (mode == FORWARD)
		{
			forward_stop = sort_forward(current, forward_stop, list, is_swap_ptr);
			current = forward_stop->prev;
			mode = BACKWARD;
		}
		else
		{
			backward_stop = sort_backward(current, backward_stop, list, is_swap_ptr);
			current = backward_stop->next;
			mode = FORWARD;
		}
	}
}

/**
 * sort_forward - Iterate through a linked list in forward direction
 * and perform swaps
 *
 * @start: The starting node for the traversal
 * @end: The end node, specifying the end of the traversal
 * @head: A double pointer to the head of the linked list
 * @is_swap: A pointer to an integer indicating whether a swap occurred during
 * the traversal
 *
 * Description: This function performs a forward traversal through a linked
 * list starting from the given starting node. It compares each node with
 * its next node, and if the current node's value is greater than the
 * next node's value, it swaps them using the swap function.
 * The traversal continues until either the end node is reached or
 * the current next node is NULL.
 * The is_swap variable is updated to indicate whether any swaps occurred
 * during the traversal.
 *
 * Return: A pointer to the last processed node in the linked list.
 */
listint_t *sort_forward(
	listint_t *start, listint_t *end, listint_t **head, int *is_swap
)
{
	listint_t *next, *current = start;

	for (; ((current->next) && current->next != end); current = current->next)
	{
		next = current->next;
		if (current->n > next->n)
		{
			*is_swap = 1;
			swap(current, next, head, FORWARD);
			current = next;
		}
	}
	return (current);
}

/**
 * sort_backward - Iterate through a linked list in backward direction
 * and perform swaps
 *
 * @start: The starting node for the traversal
 * @end: The end node, specifying the end of the traversal
 * @head: A double pointer to the head of the linked list
 * @is_swap: A pointer to an integer indicating whether a swap occurred during
 * the traversal
 *
 * Description: This function performs a backward traversal through a linked
 * list starting from the given starting node. It compares each node with
 * its prev node, and if the current node's value is less than the
 * prev node's value, it swaps them using the swap function.
 * The traversal continues until either the end node is reached or
 * the current previous node is NULL.
 * The is_swap variable is updated to indicate whether any swaps occurred
 * during the traversal.
 *
 * Return: A pointer to the last processed node in the linked list.
 */
listint_t *sort_backward(
	listint_t *start, listint_t *end, listint_t **head, int *is_swap
)
{
	listint_t *prev, *current = start;

	for (; current->prev && current->prev != end; current = current->prev)
	{
		prev = current->prev;
		if (current->n < prev->n)
		{
			*is_swap = 1;
			swap(current, prev, head, BACKWARD);
			current = prev;
		}
	}
	return (current);
}
