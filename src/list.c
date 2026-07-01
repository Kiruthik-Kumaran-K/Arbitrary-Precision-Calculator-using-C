#include "../include/apc.h"

/*
 * Inserts a digit at the beginning of the doubly linked list.
 *
 * Parameters:
 *   data - Digit to insert (0–9)
 *   head - Pointer to the head pointer
 *   tail - Pointer to the tail pointer
 *
 * Returns:
 *   STATUS_SUCCESS on success,
 *   ERR_MEMORY_ALLOCATION if allocation fails.
 */
Status insert_first(uint8_t data, Dlist **head, Dlist **tail)
{

     Dlist *new_node = create_node(data);

      if(new_node == NULL)
      {
            return ERR_MEMORY_ALLOCATION;
      }

      if(*head == NULL)
      {
            *head = new_node;
            *tail = new_node;
            return STATUS_SUCCESS;
      }

      new_node->next = *head;
      (*head)->prev = new_node;
      *head = new_node;

      return STATUS_SUCCESS;

}

/*
 * Inserts a digit at the end of the doubly linked list.
 *
 * Parameters:
 *   data - Digit to insert (0–9)
 *   head - Pointer to the head pointer
 *   tail - Pointer to the tail pointer
 *
 * Returns:
 *   STATUS_SUCCESS on success,
 *   ERR_MEMORY_ALLOCATION if allocation fails.
 */
Status insert_last(uint8_t data, Dlist **head, Dlist **tail)
{
      //Allocating memory
     Dlist *new_node = create_node(data);

      if(new_node == NULL)
      {
            return ERR_MEMORY_ALLOCATION;
      }

      
      if(*head == NULL)
      {
            *head = new_node;
            *tail = new_node;
            return STATUS_SUCCESS;
      }

      new_node->prev = *tail;
      (*tail)->next = new_node;
      *tail = new_node;
      
      return STATUS_SUCCESS;
}

/*
 * Deletes entire doubly linked list.
 *
 * Parameters:
 *   head - Pointer to the head pointer
 *   tail - Pointer to the tail pointer
 *
 * Returns:
 *   Nothing
 */
void delete_list(Dlist **head, Dlist **tail)
{

      if(head == NULL || tail ==NULL)
      {
            return;
      }

      if(*head == NULL || *tail == NULL)
      {
            return;
      }
      Dlist *current = *head;
      Dlist *temp = NULL;

      while(current)
      {
            temp = current->next; 
            free(current);
            current = temp;
      }

      *head = NULL;
      *tail = NULL;
}

static Dlist* create_node(uint8_t data)
{
      Dlist *new_node = malloc(sizeof(*new_node));

      if(new_node == NULL)
      {
            return NULL;
      }

      new_node->digit = data;
      new_node->prev = NULL;
      new_node->next = NULL;

      return new_node;
}
