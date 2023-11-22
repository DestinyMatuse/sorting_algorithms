#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers using the insertion sorting technique
 *
 * @list: list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp;
	listint_t *node_c;
	listint_t *node_p;

	tmp = *list;
	if (tmp == NULL || tmp->next == NULL)
		return;

	tmp = tmp->next;
	while (tmp != NULL)
	{
		node_c = tmp;
		while (node_c->prev != NULL && node_c->n < node_c->prev->n)
		{
			node_p = node_c->prev;
			if (node_c->next != NULL)
				node_c->next->prev = node_p;
			node_p->next = node_c->next;
			node_c->next = node_p;
			node_c->prev = node_p->prev;
			node_p->prev = node_c;
			if (node_c->prev != NULL)
				node_c->prev->next = node_c;
			else
				*list = node_c;
			print_list((*list));
		}
		tmp = tmp->next;
	}
}
