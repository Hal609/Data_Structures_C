#include <stdio.h>
#include "linked_list.h"

int main()
{
   struct linked_list list = create_list();
   append(&list, 10);
   append(&list, 22);
   append(&list, 49);
   append(&list, 101);

   print_list(&list);
   // printf("Removing item at index %i\n", -2);
   // list_remove(&list, -2);
   // print_list(&list);

   // printf("Performing multi-append.\n");
   // append_multi(&list, (u_int8_t[]){2, 4, 5, 6, 0});
   // print_list(&list);

   return 0;
}