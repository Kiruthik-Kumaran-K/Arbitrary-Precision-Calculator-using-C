#ifndef APC_H
#define APC_H

#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct node
{
      uint8_t digit;
      struct node* prev;
      struct node* next;
}Dlist;

typedef enum
{
      STATUS_SUCCESS = 0,

      ERR_ARG_COUNT,
      ERR_INVALID_OPERATOR,
      ERR_INVALID_OPERAND,

      ERR_MEMORY_ALLOCATION
}Status;

typedef enum
{
    LESS_THAN = -1,
    EQUAL = 0,
    GREATER_THAN = 1
} CompareResult;

/* Validation*/
Status validate_arguments(int argc,const char *argv[]);

/* Linked List Operation*/
Status insert_first(
      uint8_t data, 
      Dlist **head, 
      Dlist **tail);

Status insert_last(
      uint8_t data, 
      Dlist **head, 
      Dlist **tail);

void delete_list(
      Dlist **head, 
      Dlist **tail);

/* Parser */
Status create_list(
      const char *operand, 
      Dlist **head, 
      Dlist **tail);

/* Arithmetic */
Status execute_operation(
      Dlist *head1, 
      Dlist *tail1, 
      Dlist *head2, 
      Dlist *tail2,
      char operator,
      bool *negative, 
      Dlist **result_head, 
      Dlist **result_tail);

/* Output */
void print_result(const Dlist *head);


int compare_lists(
        const Dlist *head1,
        const Dlist *head2);

Status add_lists(
        Dlist *tail1,
        Dlist *tail2,
        Dlist **result_head,
        Dlist **result_tail);

Status subtract_lists(
        Dlist *tail1,
        Dlist *tail2,
        Dlist **result_head,
        Dlist **result_tail);

Status multiply_lists(
    Dlist *tail1,
    Dlist *tail2,
    Dlist **result_head,
    Dlist **result_tail); 

Status divide_lists(
        Dlist *head1,
        Dlist *head2,
        Dlist *tail2,
        Dlist **result_head,
        Dlist **result_tail);


Status copy_list(
        const Dlist *src_head,
        Dlist **dest_head,
        Dlist **dest_tail);
    
void remove_leading_zeros(Dlist **head, Dlist **tail);

bool is_zero(const Dlist *head);   

#endif


