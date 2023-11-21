#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum mode - Enumeration representing the direction mode
 *
 * @FORWARD: Represents the FORWARD direction mode
 * @BACKWARD: Represents the BACKWARD direction mode
 */
typedef enum mode
{
	FORWARD, BACKWARD
} MODE;

/**
 * enum merge_print_mode - Enumeration specifying the print mode
 * for merged arrays
 *
 * @BEFORE: Represents the print mode before the merge operation
 * @AFTER: Represents the print mode after the merge operation
 */
typedef enum merge_print_mode
{
	BEFORE, AFTER
} MERGE_PRINT_MODE;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void bubble_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

#endif
