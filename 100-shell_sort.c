#include "sort.h"


unsigned int get_sequence_gap(MODE mode, size_t from);
unsigned int get_max_sequence_gap(size_t size);
void insertion_sort(int *arr, size_t start, size_t gap, size_t size);
void swap(int *array, size_t n1_idx, size_t n2_idx);

/**
 * shell_sort - Perform shell sort on an array
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Description: This function performs shell sort on the entire array using
 * the sequence gap determined by the get_max_sequence_gap function.
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap, i;

	if (!array || size < 2)
		return;

	gap = get_max_sequence_gap(size);

	for (; gap >= 1; gap = get_sequence_gap(BACKWARD, gap))
	{
		for (i = 0; (i < size - gap); i++)
			insertion_sort(array, i, (int)gap, size);
		print_array(array, size);
	}

}

/**
 * get_sequence_gap - Get the sequence gap based on the mode and starting index
 * @mode: The mode, either FORWARD or BACKWARD
 * @from: The starting index for sequence calculation
 *
 * Description: This function calculates and returns the sequence gap based on
 * the mode and the starting index. If the mode is FORWARD, it calculates
 * the next sequence gap from the given starting index.
 * If the mode is BACKWARD, the behavior is similar but in reverse order.
 *
 * Return: The calculated sequence gap.
 */
unsigned int get_sequence_gap(MODE mode, size_t from)
{
	#define STEP_FORWARD(n) (((n) * 3) + 1)
	#define STEP_BACKWARD(n) (((n) - 1) / 3)

	return (mode == FORWARD
		? STEP_FORWARD(from)
		: STEP_BACKWARD(from));
}

/**
 * get_max_sequence_gap - Get the maximum sequence gap within a given size
 * @size: The size of the sequence
 *
 * Description: This function iterates through the sequence, calculating
 * sequence gaps in FORWARD mode, and returns the maximum gap within
 * the given size.
 *
 * Return: The maximum sequence gap.
 */
unsigned int get_max_sequence_gap(size_t size)
{
	size_t current = 1, next;

	for (next = current; next < size;
		 next = get_sequence_gap(FORWARD, current))
		if (next < size)
			current = next;

	return (current);
}

/**
 * swap - The function swaps the elements at the specified indices
 * @n1_idx and @n2_id in the array @array.
 *
 * @array: A pointer to an array of integers.
 * @n1_idx: the index of the first element to swap.
 * @n2_idx: the index of the second element to swap.
*/
void swap(int *array, size_t n1_idx, size_t n2_idx)
{
	int temp = array[n1_idx];

	if (n1_idx == n2_idx)
		return;
	array[n1_idx] = array[n2_idx];
	array[n2_idx] = temp;
}

/**
 * insertion_sort - Perform insertion sort on a portion of an array
 * @arr: The array to be sorted
 * @start: The starting index for sorting
 * @gap: The gap between elements to be compared and swapped
 * @size: The size of the array
 *
 * Description: This function performs insertion sort on a portion of the array
 * specified by the starting index, gap, and size. It is used in shell_sort for
 * sorting subarrays with a specified gap.
 */
void insertion_sort(int *arr, size_t start, size_t gap, size_t size)
{
	size_t i, to_sort;

	for (i = start + gap; i < size; i += gap)
	{
		to_sort = i;
		while (to_sort >= gap && arr[to_sort] < arr[to_sort - gap])
		{
			swap(arr, to_sort, to_sort - gap);
			to_sort -= gap;
		}
	}
}
