#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
        listint_t *head;

        head = NULL;

        /* Edge case: insert in null list */
        insert_node(&head, 0);
        print_listint(head);

        printf("-----------------\n");

        add_nodeint_end(&head, 1);
        add_nodeint_end(&head, 2);
        add_nodeint_end(&head, 3);
        add_nodeint_end(&head, 4);
        add_nodeint_end(&head, 98);
        add_nodeint_end(&head, 402);
        add_nodeint_end(&head, 1024);
        print_listint(head);

        printf("-----------------\n");

        /* Insert in the middle */
        insert_node(&head, 27);
        print_listint(head);

        /* Edge case: insert at end */
        printf("-----------------\n");
        insert_node(&head, 1025);
        print_listint(head);

        /* Edge case: insert at beginning */
        printf("-----------------\n");
        insert_node(&head, -1);
        print_listint(head);

        free_listint(head);

        return (0);
}
