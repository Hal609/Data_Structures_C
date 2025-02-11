#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct list_item
{
   char *value;
   struct list_item *next;
};

struct linked_list
{
   struct list_item *fist_item_ptr;
   int size;
};

struct linked_list create_list();
char *list_get(struct linked_list *list, int n);
void append(struct linked_list *list, char *value);
// void append_multi(struct linked_list *list, char *values);
char *pop(struct linked_list *list);
void list_remove(struct linked_list *list, int n);
void print_list(struct linked_list *list);

int in_list(struct linked_list *list, char *to_find);

#endif