#include "sort.h"
/**
 * insertion_sort_list - a function that sorts a doubly linked list
 * of integers in ascending order using the insertion sort algorithm
 * @list: linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *nxt;

	if (!list || !(*list) || !(*list)->next)
		return;

	curr = (*list)->next;

	for (nxt = (*list)->next; nxt; nxt = nxt->next)
	{
		while (curr->prev && curr->n < curr->prev->n)
		{
			curr->prev->next = curr->next;

			if (curr->next)
				curr->next->prev = curr->prev;

			curr->next = curr->prev;
			curr->prev = curr->next->prev;
			curr->next->prev = curr;

			if (curr->prev)
				curr->prev->next = curr;
			else
				*list = curr;
			print_list(*list);
		}
		curr = nxt;
	}
}
