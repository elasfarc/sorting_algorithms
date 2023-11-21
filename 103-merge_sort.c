#include "sort.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void merge(int *array, int *array_cp, size_t start, size_t middle, size_t end);
void print(MERGE_PRINT_MODE mode, int *array, size_t s, size_t m, size_t e);
void _merge_sort(int *array, int *array_cp, size_t start, size_t end);


/**
 * merge_sort - Perform merge sort on an array
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Description: This function initiates the merge sort algorithm on
 * the specified array.
 * It creates a temporary array for merging and then calls
 * the recursive _merge_sort function to perform the actual sorting.
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *array_cp = NULL;
	size_t i;

	array_cp = malloc(sizeof(int) * size);
	if (!array_cp)
		return;

	for (i = 0; i < size; i++)
		array_cp[i] = array[i];

	_merge_sort(array, array_cp, 0, size - 1);

	free(array_cp);
	array_cp = NULL;
}

/**
 * _merge_sort - Recursive helper function to perform merge sort on an array
 * @array: Pointer to the array of integers
 * @array_cp: Pointer to the temporary array used for merging
 * @start: Starting index of the array or subarray
 * @end: Ending index of the array or subarray
 *
 * Description: This function is a recursive helper function for the
 * merge sort algorithm.
 * It sorts the specified range of the array using the merge sort approach
 * by recursively dividing the array into halves and
 * merging them in sorted order.
 *
 * Return: void
 */
void _merge_sort(int *array, int *array_cp, size_t start, size_t end)
{
	size_t size = (end - start + 1), middle;
	int is_even = (int)size % 2 == 0;

	if (!array || size < 2)
		return;

	middle = (start + end) / 2;
	_merge_sort(array, array_cp, start, (is_even ? middle : middle - 1));
	_merge_sort(array, array_cp, (is_even ? middle + 1 : middle), end);

	merge(array, array_cp, start, (is_even ? middle : middle - 1), end);
}


/**
 * merge - Merge two halves of an array in sorted order
 * @array: Pointer to the original array of integers
 * @array_cp: Pointer to the temporary array used for merging
 * @start: Starting index of the first half
 * @middle: Middle index separating the two halves
 * @end: Ending index of the second half
 *
 * Description: The resulting merged array is stored in the original array.
 *
 * Return: void
 */
void merge(int *array, int *array_cp, size_t start, size_t middle, size_t end)
{
	size_t i, first_flag, seond_flag;

	i = start;
	first_flag = start;
	seond_flag = middle + 1;

	print(BEFORE, array, start, middle, end);

	while (first_flag <= middle && seond_flag <= end)
	{
		if (array_cp[first_flag] <= array_cp[seond_flag])
		{
			array[i] = array_cp[first_flag];
			first_flag++;
		}
		else
		{
			array[i] = array_cp[seond_flag];
			seond_flag++;
		}
		i++;
	}

	while (first_flag <= middle)
	{
		array[i] = array_cp[first_flag];
		first_flag++;
		i++;
	}

	while (seond_flag <= end)
	{
		array[i] = array_cp[seond_flag];
		seond_flag++;
		i++;
	}

	for (i = start; i <= end; i++)
		array_cp[i] = array[i];
	print(AFTER, array, start, middle, end);
}


/**
 * print - Print elements of an array based on the specified mode and range
 * @mode: The print mode (BEFORE or AFTER) indicating when to print elements
 * @array: Pointer to the array of integers
 * @s: Starting index of the range to be printed
 * @m: Middle index of the range to be printed
 * @e: Ending index of the range to be printed
 *
 * Description: If the mode is BEFORE, it prints elements before the
 * merge operation, and if the mode is AFTER, it prints elements after
 * the merge operation. The range is specified
 * by the starting index (s), middle index (m), and ending index (e).
 *
 * Return: void
 */
void print(MERGE_PRINT_MODE mode, int *array, size_t s, size_t m, size_t e)
{
	size_t j;

	if (mode == BEFORE)
	{
		printf("Merging...\n");
		printf("[left]: ");
		for (j = s; j <= m; j++)
			printf("%d%s", array[j], (j == m) ? "\n" : ", ");
		printf("[right]: ");
		for (j = m + 1; j <= e; j++)
			printf("%d%s", array[j], (j == e) ? "\n" : ", ");
	}
	else if (mode == AFTER)
	{
		printf("[Done]: ");
		for (j = s; j <= e; j++)
			printf("%d%s", array[j], j == e ? "\n" : ", ");
	}
}
