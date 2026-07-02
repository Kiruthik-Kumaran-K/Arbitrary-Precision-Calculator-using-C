#include "../include/apc.h"

Status add_lists(Dlist *tail1, Dlist *tail2, Dlist **result_head, Dlist **result_tail)
{
      uint8_t carry = 0;
      uint8_t digit1;
      uint8_t digit2;

      while(tail1 != NULL || tail2 != NULL || carry != 0)
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

            int sum = digit1 + digit2 + carry;

            uint8_t digit = sum % 10;

            carry = sum / 10;
            
            if(insert_first(digit, result_head, result_tail) == ERR_MEMORY_ALLOCATION)
            {
                  return ERR_MEMORY_ALLOCATION;
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

      return STATUS_SUCCESS;
}