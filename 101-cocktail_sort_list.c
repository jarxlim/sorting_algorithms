#include "sort.h"

void swap_node(listint_t **list, listint_t **tail, listint_t **swap);
void append_node(listint_t **list, listint_t **tail, listint_t **swap);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node - Swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swap: pointer to the current swapping node of the cocktail swap algo.
 */
void swap_node(listint_t **list, listint_t **tail, listint_t **swap)
{
	listint_t *temp = (*swap)->next;

	if ((*swap)->prev != NULL)
		(*swap)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*swap)->prev;
	(*swap)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *swap;
	else
		*tail = *swap;
	(*swap)->prev = temp;
	temp->next = *swap;
	*swap = temp;
}

/**
 * append_node - Swap a node in a listint_t doubly-linked
 * @list: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @swap: A pointer to the current swapping node of the cocktail swap algo.
 */
void append_node(listint_t **list, listint_t **tail, listint_t **swap)
{
	listint_t *temp = (*swap)->prev;

	if ((*swap)->next != NULL)
		(*swap)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*swap)->next;
	(*swap)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *swap;
	else
		*list = *swap;
	(*swap)->next = temp;
	temp->prev = *swap;
	*swap = temp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *swap;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (swap = *list; swap != tail; swap = swap->next)
		{
			if (swap->n > swap->next->n)
			{
				swap_node(list, &tail, &swap);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (swap = swap->prev; swap != *list;
				swap = swap->prev)
		{
			if (swap->n < swap->prev->n)
			{
				append_node(list, &tail, &swap);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
