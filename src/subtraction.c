#include "../include/apc.h"

void remove_leading_zeros(Dlist **head, Dlist **tail)
{
      if (head == NULL || tail == NULL || *head == NULL)
      {
            return;
      }

      while(*head != NULL && *head != *tail && (*head)->digit == 0)
      {
            Dlist *temp = *head;
            *head = (*head)->next;
            (*head)->prev = NULL;
            free(*temp);
      }

      return;
}

/*
 * Assumption:
 * Operand1 must be greater than or equal to Operand2.
 * Caller is responsible for comparing operands.
 */
Status subtract_lists( Dlist *tail1, Dlist *tail2, Dlist **result_head, Dlist **result_tail)
{
      uint8_t borrow = 0;
      int digit1 = 0;
      int digit2 = 0;
      int difference;

      while(tail1 != NULL || tail2 !=NULL)
      {
            if(tail1 != NULL)
            {
                  digit1 = tail1->digit;
            }
            else
            {
                  digit1 = 0;
            }


            if(tail2 != NULL)
            {
                  digit2 = tail2->digit;
            }
            else
            {
                  digit2 = 0;
            }

            digit1 = digit1 - borrow;

            if(digit1 < digit2)
            {
                  digit1 = digit1 + 10;
                  borrow = 1;
            }
            else
            {
                  borrow = 0;
            }

             difference = digit1 - digit2;

            Status status = insert_first(difference, result_head, result_tail);

            if(status != STATUS_SUCCESS)
            {
                  return status;
            }

            if(tail1 != NULL)
            {
                  tail1 = tail1->prev;
            }
            if(tail2 != NULL)
            {
                  tail2 = tail2->prev;
            }            
      }

      remove_leading_zeros(result_head , result_tail);

      return STATUS_SUCCESS;
}