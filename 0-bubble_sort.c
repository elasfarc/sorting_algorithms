#include "sort.h"


/**
 * bubble_sort - Sorts a array of integers in ascending order using
 *				 the Bubble Sort algorithm.
 *
 * @array: A pointer to a pointer to the Array.
 * @size: the array length.
 *		  The function sorts the list in place.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, first_sorted_idx = size - 1;
	int temp, is_swap = 1;

	if (!array || size < 2)
		return;

	while (is_swap)
	{
		is_swap = 0;
		for (i = 0; i < first_sorted_idx; i++)
			if (array[i + 1] < array[i])
			{
				is_swap = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		first_sorted_idx--;  /* < 0?? */
	}
}
