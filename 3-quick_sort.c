#include "sort.h"

/**
 * swap - The function swaps the elements at the specified indices
 * @n1_idx and @n2_id in the array @array.
 * It also prints the original array using the `print_array` function.
 *
 * @array: A pointer to an array of integers.
 * @n1_idx: the index of the first element to swap.
 * @n2_idx: the index of the second element to swap.
 * @source_arr: A pointer to the original array.
 * @source_size: the size of the original array.
*/
void swap(int *array, size_t n1_idx, size_t n2_idx,
	int *source_arr, int source_size)
{
	int temp = array[n1_idx];

	if (n1_idx == n2_idx)
		return;

	array[n1_idx] = array[n2_idx];
	array[n2_idx] = temp;

	print_array(source_arr, source_size);
}

/**
 * partion - performs a partition operation on an array of integers,
 * using the last element as the pivot.
 *
 * @array: a pointer to the array to be partitioned.
 * @left: the index of the leftmost element of the subarray to be partitioned.
 * @right: right: the index of the rightmost element of the subarray to
 * be partitioned.
 * @source_arr: a pointer to the original array before partitioning.
 * @source_size: the size of the original array.
 *
 * Return: the index of the pivot element after partitioning,
 * such that all elements to the left of the pivot are less than
 * or equal to it, and all elements to the right of the pivot are greater
 * than or equal to it.
*/
size_t partion(int *array, size_t left, size_t right,
	int *source_arr, size_t source_size)
{
	size_t pivot = right;

	right--;

	while (1)
	{
		while (array[left] <= array[pivot] && left < pivot)
			left++;
		while (array[right] >= array[pivot] && right != 0)
			right--;

		if (left >= right)
			break;

		swap(array, left, right, source_arr, source_size);
		left++;
	}
	swap(array, pivot, left, source_arr, source_size);

	return (left);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *					the Quick Sort algorithm.
 *
 * @array: A pointer to a pointer to the Array.
 * @size: the array length.
 *		  The function sorts the list in place.
 *
 * implementing the Lomuto partition scheme.
 * The pivot always the last element of the partition being sorted.
 */
void quick_sort(int *array, size_t size)
{
	size_t new_pivot_idx;
	static int original_size, *original_array;

	if (!original_size)
		original_size = size;
	if (!original_array)
		original_array = array;

	if (!array || size <= 1)
		return;

	new_pivot_idx = partion(array, 0, size - 1, original_array, original_size);

	quick_sort(array, new_pivot_idx);
	quick_sort(array + new_pivot_idx + 1, size - 1 - new_pivot_idx);
}
