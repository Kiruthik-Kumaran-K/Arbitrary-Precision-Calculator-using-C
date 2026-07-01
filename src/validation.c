#include "../include/apc.h"
#include <stdbool.h>

static int is_valid_operator(const char *op)
{
      int count = 0;
      int i =0;
      while(op[i] != '\0')
      {
            count++;
            i++;
      }
      if(count != 1)
      {
            return 0;
      }
      if(*op == '+' || *op == '-' || *op == '/' || *op == 'X')
      {
            return 1;
      }
      return 0;

}

static bool is_digit(char str)
{
      if(str >= '0' && str <= '9')
      {
            return true;
      }

      return false;
}

static int is_valid_operand(const char *operand)
{
      if(operand == NULL)
      {
            return 0;
      }

      if(strlen(operand) == 0)
      {
            return 0;
      }

      while(*operand != '\0')
      {
            if(!is_digit(*operand))
            {
                  return 0;
            }
            operand++;
      }

      return 1;
}


Status validate_arguments(int argc,const char *argv[])
{
      if(argc != 4)
      {
            return ERR_ARG_COUNT;
      }

      /* Validate operator*/
      int operator_valid = is_valid_operator(argv[2]); 
      if(operator_valid != 1)
      {
            return ERR_INVALID_OPERATOR;
      }

      /* Validate Opernad 1*/
      int operand1_valid = is_valid_operand(argv[1]);
      if(operand1_valid != 1)
      {
            return ERR_INVALID_OPERAND;
      }

       /* Validate Opernad 2*/
      int operand2_valid = is_valid_operand(argv[3]);
      if(operand2_valid != 1)
      {
            return ERR_INVALID_OPERAND;
      }

      return STATUS_SUCCESS;
}