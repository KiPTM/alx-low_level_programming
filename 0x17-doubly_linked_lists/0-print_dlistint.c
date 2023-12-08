#include <stdio.h>
#include "lists.h"

/**
 * print_dlistint - Prints all the elements of a dlistint_t list
 * @h: Pointer to the head of the list
 *
 * Return: The number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
    const dlistint_t *current = h;
    size_t nodes = 0;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
        nodes++;
    }

    return nodes;
}
