#include <math.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

// int main()
// {
//    struct linked_list list = create_list();
//    append(&list, 10);
//    append(&list, 22);
//    append(&list, 49);
//    append(&list, 101);

//    print_list(&list);
//    // printf("Removing item at index %i\n", -2);
//    // list_remove(&list, -2);
//    // print_list(&list);

//    // printf("Performing multi-append.\n");
//    // append_multi(&list, (u_int8_t[]){2, 4, 5, 6, 0});
//    // print_list(&list);

//    return 0;
// }

FILE *readTXT(char *filename)
{
   FILE *fp;                  // declaration of file pointer
   fp = fopen(filename, "r"); // opening of file
   if (!fp)
   {
      fprintf(stderr, "ERROR: File not opened.\n");
      return NULL;
   }

   return fp;
}

static int MAX_WORD_LEN = 28;

int is_lower(char c)
{
   return ((c >= 97) && (c <= 122));
}
int is_upper(char c)
{
   return ((c >= 65) && (c <= 90));
}
int is_alphabetic(char c)
{
   return (is_upper(c) || is_lower(c));
}

char to_lower(char c)
{
   if (is_upper(c))
      return (c + 32);
   return c;
}

int main()
{
   struct linked_list unique_words = create_list();
   char c;
   FILE *file;
   file = fopen("sherlockHolmes.txt", "r");
   if (file)
   {
      char word[MAX_WORD_LEN];
      int x = 0;
      while ((c = getc(file)) != EOF)
      {
         c = to_lower(c);
         if (is_alphabetic(c))
         {
            word[x] = c;
            x = fmin(x + 1, MAX_WORD_LEN - 1);
         }
         else
         {
            if (x > 0)
            {
               if (!in_list(&unique_words, word))
               {
                  char *copy = malloc(strlen(word) + 1);
                  strcpy(copy, word);
                  append(&unique_words, copy);
               }
               for (int i = 0; i < MAX_WORD_LEN; i++)
                  word[i] = 0;
               x = 0;
            }
         }
      }
   }
   fclose(file);

   printf("%i unique words.\n", unique_words.size);
   print_list(&unique_words);
   return 0;
}