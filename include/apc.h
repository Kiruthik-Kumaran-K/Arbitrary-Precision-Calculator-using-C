#ifndef APC_H
#define APC_H

#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

typedef struct node
{
      uint8_t digit;
      struct node* prev;
      struct node* next;
}Dlist;

// typedef struct
// {
//     Dlist *head;
//     Dlist *tail;
// } BigInteger;

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
      Dlist **result_head, 
      Dlist **result_tail);

/* Output */
void print_result(const Dlist *head);

int compare_lists(
        Dlist *head1,
        Dlist *head2);

Status add_lists(
        Dlist *tail1,
        Dlist *tail2,
        Dlist **result_head,
        Dlist **result_tail);

Status subtract_lists(
        Dlist *head1,
        Dlist *tail1,
        Dlist *head2,
        Dlist *tail2,
        Dlist **result_head,
        Dlist **result_tail);

Status multiply_lists(...);

Status divide_lists(...);

#endif

/*

int compare_lists(...);

int get_length(...);

void remove_leading_zeros(...);

Status copy_list(...);

*/
