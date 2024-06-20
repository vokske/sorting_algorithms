#include "sort.h"

/**
 * quick_sort - sorts an array of integers
 * in ascending order using the Quick sort algorithm
 *
 * @array: The array to be sorted
 * @size: Size of @array
 */
void quick_sort(int *array, size_t size)
{
	int same_elements;
	size_t i;

	if (size <= 1)
	{
		print_array(array, size);
		return;
	}
	same_elements = 1;

	for (i = 1; i < size; i++)
	{
		if (array[i] != array[0])
		{
			same_elements = 0;
			break;
		}
	}

	if (same_elements)
	{
		print_array(array, size);
		return;
	}
	sort_subarray(array, 0, size - 1, size);
}

/**
 * sort_subarray - Helper function to recursively sort the
 * left and right subarrays formed after partitioning original array
 *
 * @array: Array to be sorted
 * @start: The beginning of the array
 * @end: The end of the array
 */

void sort_subarray(int *array, size_t start, size_t end, size_t orig_size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition_array(array, start, end, orig_size);

		if (pivot_index > 0)
		{
			sort_subarray(array, start, pivot_index - 1, orig_size);
		}
		sort_subarray(array, pivot_index + 1, end, orig_size);
	}
}

/**
 * partition_array - Partitions the original array into
 * subarrays using the Lomuto partition scheme
 *
 * @array: The array to be sorted
 * @start: Beginning of @array
 * @end: End of @array
 *
 * Return: Index of the pivot element
 */

int partition_array(int *array, size_t start, size_t end, size_t orig_size)
{
	int pivot, temp;
	long unsigned int i, j;

	pivot = array[end];
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{	i++;
			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
				print_array(array, orig_size);
			}
		}
	}
	if (i + 1 != end)
	{
		temp = array[end];
		array[end] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, orig_size);
	}

	return (i + 1);
}
