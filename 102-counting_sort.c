#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void free_safe(void *v);

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *					the Counting Sort algorithm.
 *
 * @array: A pointer to a pointer to the Array.
 * @size: the array length.
 *		  The function sorts the list in place.
 */
void counting_sort(int *array, size_t size)
{
	int max_val = 0, num, *counting_arr = NULL, *array_copy = NULL;
	ssize_t i, num_sorted_idx;

	if (!array || size < 2)
		return;

	for (i = 0; i < (long)size; i++)
		if (array[i] > max_val)
			max_val = array[i];

	counting_arr = malloc(sizeof(int) * (max_val + 1));
	array_copy = malloc(sizeof(int) * size);
	if (!array_copy || !counting_arr)
	{
		free_safe(counting_arr);
		free_safe(array_copy);
		return;
	}
	for (i = 0; i <= max_val; i++)
		counting_arr[i] = 0;

	for (i = 0; i < (long)size; i++)
	{
		array_copy[i] = array[i];
		num = array[i];
		counting_arr[num] += 1;
	}
	for (i = 1; i <= max_val; i++)
		counting_arr[i] += counting_arr[i - 1];

	print_array(counting_arr, max_val + 1);
	for ((i = size - 1); i >= 0; i--)
	{
		num = array_copy[i];
		num_sorted_idx = counting_arr[num] - 1;
		array[num_sorted_idx] = num;
		counting_arr[num] -= 1;
	}
	free_safe(counting_arr);
	free_safe(array_copy);
}


/**
 * free_safe - Safely free a dynamically allocated memory block
 * @v: Pointer to the memory block to be freed
 *
 * Return: void
 */
void free_safe(void *v)
{
	if (v)
		free(v);
}
