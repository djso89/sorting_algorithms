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

	curr = nxt = (*list)->next;

	for (; nxt; curr = nxt)
	{
		for (nxt = nxt->next; curr->prev && curr->n < curr->prev->n;
		      print_list(*list))
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
		}
	}
}
