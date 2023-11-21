#include "sort.h"
#include <stddef.h>

/**
 * swap - Swaps two elements in an array and prints the array
 * @array: The array to be modified
 * @item1: Index of the first element to be swapped
 * @item2: Index of the second element to be swapped
 */
void swap(int *array, size_t item1, size_t item2)
{
    if (array[item1] != array[item2])
    {
        int tmp = array[item1];
        array[item1] = array[item2];
        array[item2] = tmp;
        print_array(array, item2 + 1);  // Print array after each swap
    }
}

/**
 * lomuto_partition - Implements Lomuto partition scheme
 * @array: The array to be partitioned
 * @first: Index of the first element of the partition
 * @last: Index of the last element of the partition
 * @size: Size of the array
 * Return: Index of the pivot element
 */
size_t lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
    int pivot = array[last];
    ssize_t current = first, finder;

    for (finder = first; finder < last; finder++)
    {
        if (array[finder] < pivot)
        {
            swap(array, current, finder);
            current++;
        }
    }

    swap(array, current, last);

    return (current);
}

/**
 * quick_sort_recursive - Recursively sorts the array using QuickSort
 * @array: The array to be sorted
 * @first: Index of the first element of the partition
 * @last: Index of the last element of the partition
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, ssize_t first, ssize_t last, size_t size)
{
    if (first < last)
    {
        size_t position = lomuto_partition(array, first, last, size);

        quick_sort_recursive(array, first, position - 1, size);
        quick_sort_recursive(array, position + 1, last, size);
    }
}

/**
 * quick_sort - Sorts an array of integers in ascending order using QuickSort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

