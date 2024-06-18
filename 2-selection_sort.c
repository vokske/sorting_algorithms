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
	int smallest_num, temp;
	unsigned long int i, j, smallest_index;

	for (i = 0; i < size - 1; i++)
	{
		smallest_num = array[i];
		smallest_index = i;

		for (j = i; j < size; j++)
		{
			if (smallest_num > array[j])
			{
				smallest_num = array[j];
				smallest_index = j;
			}
		}
		if (smallest_index != i)
		{
			temp = array[i];
			array[i] = array[smallest_index];
			array[smallest_index] = temp;
			print_array(array, size);
		}
	}
}
