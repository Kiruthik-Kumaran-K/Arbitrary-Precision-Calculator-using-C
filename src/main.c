#include <stdio.h>
#include "../include/apc.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
      //Declare all the required linked list
      Dlist *head1 = NULL;
      Dlist *tail1 = NULL;

      Dlist *head2 = NULL;
      Dlist *tail2 = NULL;

      Dlist *result_head = NULL;
      Dlist *result_tail = NULL;

      //Validate command-line argument
      
      status = validate_arguments(argc, argv);

      switch(status)
      {
            case 1:
            printf("SUCCESS : Validation Complete\n");
            break;

            case 2:
            printf("ERROR : Wrong Argument count\n");
            break;

            case 3:
            printf("ERROR : Invalid Operator\n");
            break;

            case 4:
            printf("ERROR : Inavlid Operand\n");
            break;

            case 5:
            printf("ERROR : Dividing by Zero\n");
            break;
      }
   
      
      
      //Convert operand1 strint to linked list
     if(create_list(argv[1], &head1, &tail1) != SUCCESS) 
     {
      return FAILURE;
     }

      //Convert operand2 string to linked list
      if(create_list(argv[3], &head2, &tail2) != SUCCESS)
      {
            delete_list(&head1, &tail1);
            return FAILURE;
      }

      //perform requested arithmetic operation
      if(perform_operation(head1, tail1, head2, tail2, argv[2][0], &result_head, &result_tail) != SUCCESS)
      {
            delete_list(&head1, &tail1);
            delete_list(&head2, &tail2); 
      }

      //Print the result
      print_result(result_head);

      //Free all allocated memory
      delete_list(&head1, &tail1);
      delete_list(&head2, &tail2);
      delete_list(&result_head, &result_tail);


      return SUCCESS;
}