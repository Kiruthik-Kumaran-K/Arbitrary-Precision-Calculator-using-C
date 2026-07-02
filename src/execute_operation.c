#include "../include/apc.h"

Status execute_operation(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, char operator,bool *negative, Dlist **result_head, Dlist **result_tail)
{
      *negative = false;
      Status status = STATUS_SUCCESS;
      switch (operator)
      {
            case '+':
                  status = add_lists(tail1, tail2, result_head, result_tail);
                  break;

            case '-':
            {
                  CompareResult compare_result = compare_lists(head1, head2);

                  if (compare_result == GREATER_THAN)
                  {
                        status = subtract_lists(tail1, tail2, result_head, result_tail);
                  }
                  else if (compare_result == LESS_THAN)
                  {
                        *negative = true;
                        status = subtract_lists(tail2, tail1, result_head, result_tail);
                  }
                  else
                  {
                        status = insert_first(0, result_head, result_tail);
                  }
                  break;
            }

            case 'X':
                  status = multiply_lists( tail1, tail2, result_head, result_tail);
                  break;

            case '/':
                  // status = divide_lists(/* arguments */);
                  break;

            default:
                  status = ERR_INVALID_OPERATOR;
            break;
}
      return status;
}