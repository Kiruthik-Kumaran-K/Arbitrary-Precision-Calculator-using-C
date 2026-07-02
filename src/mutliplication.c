#include "../include/apc.h"

/*
 * Appends trailing zeros to a linked list.
 */
static Status append_zeros(Dlist **head, Dlist **tail, size_t count)
{
    while (count--)
    {
        Status status = insert_last(0, head, tail);
        if (status != STATUS_SUCCESS)
        {
            return status;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * Multiplies a linked-list number by a single digit.
 */
static Status multiply_digit(Dlist *tail,uint8_t digit, Dlist **result_head, Dlist **result_tail)
{
    /* Fast path: anything × 0 = 0 */
    if (digit == 0)
    {
        return insert_first(0, result_head, result_tail);
    }

    int carry = 0;

    while (tail != NULL || carry != 0)
    {
        int value = (tail != NULL) ? tail->digit : 0;

        int product = value * digit + carry;

        carry = product / 10;

        int result_digit = product % 10;

        Status status = insert_first(result_digit, result_head, result_tail);

        if (status != STATUS_SUCCESS)
        {
            delete_list(result_head, result_tail);
            return status;
        }

        if (tail != NULL)
        {
            tail = tail->prev;
        }
    }

    return STATUS_SUCCESS;
}

/*
 * Multiplies two arbitrary precision integers.
 */
Status multiply_lists(Dlist *tail1, Dlist *tail2, Dlist **result_head, Dlist **result_tail)
{
    Status status;
    size_t shift = 0;

    while (tail2 != NULL)
    {
        Dlist *partial_head = NULL;
        Dlist *partial_tail = NULL;

        Dlist *sum_head = NULL;
        Dlist *sum_tail = NULL;

        /* Multiply operand1 by one digit of operand2 */
        status = multiply_digit(tail1,
                                tail2->digit,
                                &partial_head,
                                &partial_tail);

        if (status != STATUS_SUCCESS)
        {
            delete_list(&partial_head, &partial_tail);
            return status;
        }

        /* Shift according to digit position */
        status = append_zeros(&partial_head,
                              &partial_tail,
                              shift);

        if (status != STATUS_SUCCESS)
        {
            delete_list(&partial_head, &partial_tail);
            return status;
        }

        /*
         * First partial product becomes the result.
         * No need to add it to zero.
         */
        if (*result_head == NULL)
        {
            *result_head = partial_head;
            *result_tail = partial_tail;
        }
        else
        {
            status = add_lists(*result_tail,
                               partial_tail,
                               &sum_head,
                               &sum_tail);

            if (status != STATUS_SUCCESS)
            {
                delete_list(&partial_head, &partial_tail);
                delete_list(&sum_head, &sum_tail);
                delete_list(result_head, result_tail);
                return status;
            }

            /* Free previous result */
            delete_list(result_head, result_tail);

            /* Replace with new sum */
            *result_head = sum_head;
            *result_tail = sum_tail;

            /* Partial list no longer needed */
            delete_list(&partial_head, &partial_tail);
        }

        shift++;
        tail2 = tail2->prev;
    }

    /* Safety: if both operands somehow produced no result */
    if (*result_head == NULL)
    {
        status = insert_first(0, result_head, result_tail);

        if (status != STATUS_SUCCESS)
        {
            return status;
        }
    }

    remove_leading_zeros(result_head, result_tail);

    return STATUS_SUCCESS;
}