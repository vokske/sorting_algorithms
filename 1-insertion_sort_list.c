#include "sort.h"

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *current, *next_node;

	if (*list == NULL || (*list)->next == NULL || list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next_node = current->next;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;

			if (temp->prev != NULL)
				temp->prev->next = current;
			
			current->prev = temp->prev;
			temp->next = current->next;

			if (current->next != NULL)
				current->next->prev = temp;

			current->next = temp;
			temp->prev = current;

			if (current->prev == NULL)
				*list = current;

			print_list(*list);
		}
		current = next_node;
	}
}
