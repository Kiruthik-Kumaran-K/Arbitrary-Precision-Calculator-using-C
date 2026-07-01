#include <stdio.h>
#include "../include/apc.h"

Status insert_last(uint8_t data, Dlist **head, Dlist **tail)
{
      //Allocating memory
      Dlist *new_node = malloc(sizeof(Dlist));

      if(new_node == NULL)
      {
            return ERR_MEMORY_ALLOCATION;
      }

      new_node->digit = data;
      new_node->next = NULL;
      new_node->prev = NULL;
      
      if(*head == NULL)
      {
            *head = new_node;
            *tail = new_node;
            return STATUS_SUCCESS;
      }

      new_node -> prev = *tail;
      (*tail) -> next = new_node;
      *tail = new_node;
      
      return STATUS_SUCCESS;
}

void delete_list(Dlist **head, Dlist **tail)
{

      if(*head == NULL || *tail == NULL)
      {
            return ;
      }
      Dlist *current = *head;
      Dlist *temp = NULL;

      while(current)
      {
            temp = current->next 
            free(current);
            current = temp;
      }

      *head = NULL;
      *tail = NULL;
}

Status insert_first(uint8_t data, Dlist **head, Dlist **tail)
{

      Dlist *new_node = malloc(sizeof(Dlist));

      if(new_node == NULL)
      {
            return ERR_MEMORY_ALLOCATION;
      }

      new_node->digit = data;
      new_node->prev = NULL;
      new_node->next = NULL; 

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