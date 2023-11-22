#include "sort.h"

/**
 * f_swap - Function that swaps two values
 *
 * @first: First value
 * @second: Second value
 */
void f_swap(int *first, int *second)
{
	int i;

	i = *second;
	*second = *first;
	*first = i;
}


/**
 * f_quick - the sorting algorithm
 *
 * @array: array to be sorted
 * @left_s: left side of the array
 * @right_s: right side of the array
 * @size: size of the array
 */
void f_quick(int *array, int left_s, int right_s, size_t size)
{
	int *m_pivot;
	int i = left_s - 1, j;

	if (left_s >= right_s)
		return;

	m_pivot = array + right_s;

	for (j = left_s; j < right_s; j++)
	{
		if (array[j] < *m_pivot)
		{
			i++;
			if (i < j)
			{
				f_swap(array + j, array + i);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > *m_pivot)
	{
		f_swap(array + i + 1, m_pivot);
		print_array(array, size);
	}
	f_quick(array, left_s, i, size);
	f_quick(array, i + 2, right_s, size);
}

/**
 * quick_sort - sorts an array of data using quicksort algorithms
 *
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	f_quick(array, 0, size - 1, size);
}
