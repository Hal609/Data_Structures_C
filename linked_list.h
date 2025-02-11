#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <stdlib.h>

struct list_item
{
   uint8_t value;
   struct list_item *next;
};

struct linked_list
{
   struct list_item *fist_item_ptr;
   uint8_t size;
};

struct linked_list create_list();
uint8_t list_get(struct linked_list *list, int8_t n);
void append(struct linked_list *list, uint8_t value);
void append_multi(struct linked_list *list, uint8_t *values);
uint8_t pop(struct linked_list *list);
void list_remove(struct linked_list *list, int8_t n);
void print_list(struct linked_list *list);

#endif