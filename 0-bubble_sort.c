#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	long unsigned int i, j;
	int temp, swap_flag;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		swap_flag = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swap_flag = 1;
			}
		}
		if (swap_flag == 0)
			break;
		print_array(array, size);
	}
	printf("\n");
}
