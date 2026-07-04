#include "../include/apc.h"

bool is_zero(const Dlist *head)
{
    while(head)
    {
        if(head->digit != 0)
        {
            return false;
        }

        head = head->next;
    }

    return true;
}

Status copy_list(const Dlist *src_head, Dlist **dest_head, Dlist **dest_tail)
{
    while (src_head != NULL)
    {
        Status status = insert_last(src_head->digit, dest_head, dest_tail);

        if (status != STATUS_SUCCESS)
        {
            delete_list(dest_head, dest_tail);
            return status;
        }

        src_head = src_head->next;
    }

    return STATUS_SUCCESS;
}

static void replace_list(Dlist **head, Dlist **tail, Dlist **new_head, Dlist **new_tail)
{
    delete_list(head, tail);

    *head = *new_head;
    *tail = *new_tail;

    *new_head = NULL;
    *new_tail = NULL;
}

Status divide_lists( Dlist *head1, Dlist *head2, Dlist *tail2, Dlist **result_head, Dlist **result_tail)
{
    Status status;

    Dlist *current_head = NULL;
    Dlist *current_tail = NULL;

    Dlist *one_head = NULL;
    Dlist *one_tail = NULL;

    Dlist *temp_head = NULL;
    Dlist *temp_tail = NULL;

    Dlist *new_result_head = NULL;
    Dlist *new_result_tail = NULL;

    /* Copy dividend */
    status = copy_list(head1, &current_head, &current_tail);

    if(status != STATUS_SUCCESS)
    {
        return status;
    }

    /* Quotient = 0 */
    status = insert_first(0, result_head, result_tail);

    if(status != STATUS_SUCCESS)
    {
        delete_list(&current_head, &current_tail);

        return status;
    }

    /* Constant ONE */
    status = insert_first(1, &one_head, &one_tail);

    if(status != STATUS_SUCCESS)
    {
        delete_list(&current_head, &current_tail);

        delete_list(result_head,result_tail);

        return status;
    }

    while(compare_lists(current_head, head2) != LESS_THAN)
    {
        /* current = current - divisor */

        status = subtract_lists(current_tail, tail2, &temp_head, &temp_tail);

        if(status != STATUS_SUCCESS)
        {
            break;
        }

        replace_list(&current_head, &current_tail, &temp_head, &temp_tail);

        /* quotient = quotient + 1 */

        status = add_lists(*result_tail, one_tail, &new_result_head, &new_result_tail);

        if(status != STATUS_SUCCESS)
        {
            break;
        }

        replace_list(result_head, result_tail, &new_result_head, &new_result_tail);
    }

    delete_list(&current_head, &current_tail);

    delete_list(&one_head, &one_tail);

    remove_leading_zeros(result_head,result_tail);

    return STATUS_SUCCESS;
}