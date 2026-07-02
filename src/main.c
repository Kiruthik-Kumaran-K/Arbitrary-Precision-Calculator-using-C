// #include <stdio.h>
// #include "../include/apc.h"
// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>

// int main(int argc, char *argv[])
// {
//       Status status; 
//       //Declare all the required linked list
//       Dlist *head1 = NULL;
//       Dlist *tail1 = NULL;

//       Dlist *head2 = NULL;
//       Dlist *tail2 = NULL;

//       Dlist *result_head = NULL;
//       Dlist *result_tail = NULL;

//       //Validate command-line argument
      
//       status = validate_arguments(argc, argv);

//       switch(status)
//       {
//             case STATUS_SUCCESS:
//             printf("SUCCESS : Validation Complete\n");
//             break;

//             case ERR_ARG_COUNT:
//             printf("ERROR : Wrong Argument count\n");
//             break;

//             case ERR_INVALID_OPERATOR:
//             printf("ERROR : Invalid Operator\n");
//             break;

//             case ERR_INVALID_OPERAND:
//             printf("ERROR : Inavlid Operand\n");
//             break;
//       }
   
      
      
//       //Convert operand1 strint to linked list
//      if(create_list(argv[1], &head1, &tail1) != SUCCESS) 
//      {
//       return FAILURE;
//      }

//       //Convert operand2 string to linked list
//       if(create_list(argv[3], &head2, &tail2) != SUCCESS)
//       {
//             delete_list(&head1, &tail1);
//             return FAILURE;
//       }

//       //perform requested arithmetic operation
//       if(perform_operation(head1, tail1, head2, tail2, argv[2][0], &result_head, &result_tail) != SUCCESS)
//       {
//             delete_list(&head1, &tail1);
//             delete_list(&head2, &tail2); 
//       }

//       //Print the result
//       print_result(result_head);

//       //Free all allocated memory
//       delete_list(&head1, &tail1);
//       delete_list(&head2, &tail2);
//       delete_list(&result_head, &result_tail);


//       return SUCCESS;
// }

#include "../include/apc.h"

int main(int argc, char *argv[])
{
    /* Linked lists for operands and result */
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *result_head = NULL;
    Dlist *result_tail = NULL;

    bool negative = false;
    Status status;

    /* Validate command-line arguments */
    status = validate_arguments(argc, (const char **)argv);

    switch (status)
    {
        case STATUS_SUCCESS:
            break;

        case ERR_ARG_COUNT:
            printf("ERROR: Wrong number of arguments.\n");
            return EXIT_FAILURE;

        case ERR_INVALID_OPERATOR:
            printf("ERROR: Invalid operator.\n");
            return EXIT_FAILURE;

        case ERR_INVALID_OPERAND:
            printf("ERROR: Invalid operand.\n");
            return EXIT_FAILURE;

        default:
            printf("ERROR: Validation failed.\n");
            return EXIT_FAILURE;
    }

    /* Create first operand list */
    status = create_list(argv[1], &head1, &tail1);
    if (status != STATUS_SUCCESS)
    {
        printf("ERROR: Failed to create first operand list.\n");
        return EXIT_FAILURE;
    }

    /* Create second operand list */
    status = create_list(argv[3], &head2, &tail2);
    if (status != STATUS_SUCCESS)
    {
        printf("ERROR: Failed to create second operand list.\n");

        delete_list(&head1, &tail1);
        return EXIT_FAILURE;
    }

    /* Perform arithmetic operation */
    status = execute_operation(head1, tail1, head2, tail2, argv[2][0], &negative, &result_head, &result_tail);

    if (status != STATUS_SUCCESS)
    {
        printf("ERROR: Failed to execute operation.\n");

        delete_list(&head1, &tail1);
        delete_list(&head2, &tail2);
        delete_list(&result_head, &result_tail);

        return EXIT_FAILURE;
    }

    /* Print sign if required */
    if (negative)
    {
        printf("-");
    }

    /* Print result */
    print_result(result_head);

    /* Free allocated memory */
    delete_list(&head1, &tail1);
    delete_list(&head2, &tail2);
    delete_list(&result_head, &result_tail);

    return EXIT_SUCCESS;
}