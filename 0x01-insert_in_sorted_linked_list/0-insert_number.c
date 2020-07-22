#include "lists.h"

/**
 * insert_node - insert a new node in a sorted listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
        listint_t *new;
        listint_t *current;

        current = *head;

        new = malloc(sizeof(listint_t));
        if (new == NULL)
                return (NULL);

        new->n = number;
        new->next = NULL;

        if (*head == NULL)
        {
                *head = new;
        }
        else if (current->n > number)
        {
                new->next = current;
                *head = new;
        }
        else
        {
                while (current->next != NULL && current->next->n < number)
                        current = current->next;

                new->next = current->next;
                current->next = new;
        }

        return (new);
}
