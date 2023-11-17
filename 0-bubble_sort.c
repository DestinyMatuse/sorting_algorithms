#include "sort.h"

/**
 * bubble_sort - Implement the bubble sort algorithm
 *
 * @array: Array of integers to be sorted
 * @size: Size of array
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, k,  swap;
	swap = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size; j++)
		{
			if array[j] > array[j - 1]
				continue;
			else
			{
				k = array[j];
				array[j] = array[j - 1];
				array[j - 1] = k;
				swap += 1;
				print_array(array, size);

			}
			j++;
		}
		if swap == 0
			return;
		swap = 0;
	}
	return (0);
}
