#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct linked_list create_list()
{
   struct linked_list list;

   list.fist_item_ptr = (struct list_item *)malloc(sizeof(struct list_item));
   list.size = 0;

   return list;
}

uint8_t list_get(struct linked_list *list, int8_t n)
{
   if (abs(n) >= list->size)
   {
      fprintf(stderr, "ERROR: n must not exceed list size.");
      return 1;
   }
   if (n < 0)
   {
      n = list->size + n;
   }

   uint8_t counter = 0;
   struct list_item *current_item_address = list->fist_item_ptr;
   while (counter <= n)
   {
      if (n == counter)
      {
         return current_item_address[0].value;
      }
      else
      {
         current_item_address = current_item_address[0].next;
         counter++;
      }
   }

   fprintf(stderr, "ERROR: No item at %i found", n);
   return 1;
}

struct list_item *_get_list_nth_address(struct linked_list list, uint8_t n)
{
   if (n >= list.size)
   {
      fprintf(stderr, "ERROR: N exceeded list size.");
      return NULL;
   }

   uint8_t counter = 0;
   struct list_item *current_item_address = list.fist_item_ptr;
   while (counter <= n)
   {
      if (n == counter)
      {
         return current_item_address;
      }
      else
      {
         current_item_address = current_item_address[0].next;
         counter++;
      }
   }

   fprintf(stderr, "ERROR: No item at %i found", n);
   return NULL;
}

void _set_nth_item_next(struct linked_list *list, uint8_t n, struct list_item *next_ptr)
{
   if (n >= list->size)
   {
      fprintf(stderr, "ERROR: N exceeded list size.");
   }

   uint8_t counter = 0;
   struct list_item *current_item_address = list->fist_item_ptr;
   while (counter <= n)
   {
      if (n == counter)
      {
         current_item_address[0].next = next_ptr;
         break;
      }
      else
      {
         current_item_address = current_item_address[0].next;
         counter++;
      }
   }
}

void append(struct linked_list *list, uint8_t value)
{
   struct list_item *next_item_ptr = (struct list_item *)malloc(sizeof(struct list_item));
   if (list->size == 0)
      next_item_ptr = list->fist_item_ptr;
   struct list_item next_item;
   next_item.value = value;
   next_item.next = NULL;
   next_item_ptr[0] = next_item;
   if (list->size != 0)
      _set_nth_item_next(list, list->size - 1, next_item_ptr);
   list->size++;
}

uint8_t pop(struct linked_list *list)
{
   if (list->size == 0)
   {
      fprintf(stderr, "ERROR: Cannot pop from empty list.");
      return 1;
   }
   struct list_item *last_ptr = _get_list_nth_address(*list, list->size - 1);
   list->size--;
   _set_nth_item_next(list, list->size - 1, NULL);
   uint8_t value = last_ptr->value;
   free(last_ptr);

   return value;
}

void list_remove(struct linked_list *list, int8_t n)
{
   if (abs(n) >= list->size)
   {
      fprintf(stderr, "ERROR: n must not exceed list size.");
      return;
   }
   if (n < 0)
   {
      n = list->size + n;
   }
   // Get next address of nth item
   struct list_item *nth_ptr = _get_list_nth_address(*list, n);
   if (n == 0)
   {
      list->fist_item_ptr = nth_ptr->next;
   }
   else
   {
      // Set n-1th item's next pointer to stored next address
      _set_nth_item_next(list, n - 1, (*nth_ptr).next);
   }
   // Free nth item
   free(nth_ptr);
   list->size--;
}

void print_list(struct linked_list *list)
{
   printf("[");
   for (int i = 0; i < list->size - 1; i++)
   {
      printf("%i, ", list_get(list, i));
   }
   printf("%i]\n", list_get(list, list->size - 1));
}

void append_multi(struct linked_list *list, uint8_t *values)
{
   while (*values)
   {
      uint8_t x = *values++;
      append(list, x);
   }
}