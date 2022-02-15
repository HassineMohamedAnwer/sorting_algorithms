#include "sort.h"
/**
 * swap - check the code
 * @cur: current
 * @nx: next
 * Return: none
 */
void swap(listint_t *cur, listint_t *nx)
{
	if (cur->prev)
		cur->prev->next = nx;
	if (nx->next)
		nx->next->prev = cur;
	cur->next = nx->next;
	nx->prev = cur->prev;
	cur->prev = nx;
	nx->next = cur;
}

/**
 * insertion_sort_list - check the code
 *
 * @list: list
 *
 *
 * Return: None
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *nx;

	if (!(list && (*list) && (*list)->next))
		return;
	nx = (*list)->next;
	while (nx)
	{
		cur = nx;
		nx = nx->next;
		while (cur->prev)
		{
			if (cur->prev->n > cur->n)
			{
				swap(cur->prev, cur);
				if (cur->prev == NULL)
					*list = cur;
				print_list(*list);
			}
			else
				cur = cur->prev;
		}
	}
}
