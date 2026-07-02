#include "../include/apc.h"

static size_t get_length(const Dlist *head)
{
      const Dlist *current = head;
      size_t count = 0;
      while(current)
      {
            count++;
            current = current->next;
      }

      return count;
}

int compare_lists(const Dlist *head1, const Dlist *head2)
{
      size_t count_operand1 = get_length(head1);
      size_t count_operand2 = get_length(head2);

      const Dlist *current1 = head1;  const Dlist *current2 = head2;
      
      if(count_operand1 == count_operand2)
      {
            while(current1)
            {
                  if((current1->digit) > (current2->digit))
                  {
                        return GREATER_THAN;
                  }

                  if((current1->digit) < (current2->digit))
                  {
                        return LESS_THAN;
                  }

                  current1 = current1->next;
                  current2 = current2->next;
            }
            return EQUAL;
      }

      if(count_operand1 > count_operand2)
      {
            return GREATER_THAN;
      }

      // if(count_operand1 < count_operand2)
      // {
      //       return LESS_THAN;
      // }
      return LESS_THAN;
}