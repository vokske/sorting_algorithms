#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 *
 * @array: Pointer to the array to be sorted
 * @size: Size of @array
 */

void selection_sort(int *array, size_t size)
{
	int start_point, smallest_num, smallest_index, temp;
	unsigned long int i, j;

	for (i = 0; i < size - 1; i++)
	{
		start_point = i;
		smallest_num = array[start_point];

		for (j = start_point; j < size; j++)
		{
			if (smallest_num > array[j])
			{
				smallest_num = array[j];
				smallest_index = j;
			}
		}
		temp = array[smallest_index];
		array[smallest_index] = array[start_point];
		array[start_point] = temp;
		start_point++;
		print_array(array, size);
	}
}
