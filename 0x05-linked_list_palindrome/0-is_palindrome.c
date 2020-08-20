#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
    new->next = *head;
    *head = new;

	return (new);
}

/**
 * is_palindrome - check if a linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 1 if it's a palindrome, 0 if it's not
 */
int is_palindrome(listint_t **head)
{
    listint_t *reverse;
    listint_t *reverse_head;
    listint_t *current;
    int size = 0, i = 0;

    reverse = NULL;
    current = *head;
    while (current)
    {
        add_nodeint(&reverse, current->n);
        current = current->next;
        size++;
    }

    current = *head;
    reverse_head = reverse;
    while (i < size / 2)
    {
        if (current->n != reverse->n)
        {
            free_listint(reverse_head);
            return (0);
        }
        current = current->next;
        reverse = reverse->next;
        i++;
    }

    free_listint(reverse_head);
	return (1);
}
