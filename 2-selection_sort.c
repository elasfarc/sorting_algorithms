#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 *					the Selection Sort algorithm.
 *
 * @array: A pointer to a pointer to the Array.
 * @size: the array length.
 *		  The function sorts the list in place.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, lowest_num_idx;
	int temp;

	for (i = 0; i < size; i++)
	{
		lowest_num_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[lowest_num_idx])
				lowest_num_idx = j;
		if (array[lowest_num_idx] < array[i])
		{
			temp = array[i];
			array[i] = array[lowest_num_idx];
			array[lowest_num_idx] = temp;
			print_array(array, size);
		}
	}
}
