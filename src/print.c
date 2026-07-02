#include "../include/apc.h"

void print_result(const Dlist *head)
{
    while (head != NULL)
    {
        printf("%u", head->digit);
        head = head->next;
    }

    printf("\n");
}