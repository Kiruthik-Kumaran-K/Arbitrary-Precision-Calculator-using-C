#include "../include/apc.h"


Status create_list(const char *operand, Dlist **head, Dlist **tail)
{
    if(operand == NULL)
    {
      return ERR_INVALID_OPERAND;
    }  

    Status status = STATUS_SUCCESS;
    size_t i = 0;
    while(operand[i])
    {
    uint8_t data = operand[i] - '0';
    status = insert_last(data, head, tail);
    if(status  == STATUS_SUCCESS)
    {
            i++;
    }else{
      delete_list(head, tail);
      return status;
    }
    }

      return status;
}