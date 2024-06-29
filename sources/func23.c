#include <stdio.h>
#include <glib.h>
#include "../includes/func23.h"

void func23() {
    //Basic operations of arrays
    GArray * a = g_array_new(FALSE, FALSE, sizeof(char *));
    char * first = "hello", * second = "there", * third = "world";
    g_array_append_val(a, first);
    g_array_append_val(a, second);
    g_array_append_val(a, third);
    printf("There are now %d items in the array\n", a->len);
    printf("The first item is '%s'\n", g_array_index(a, char *, 0));
    printf("The third item is '%s'\n", g_array_index(a, char *, 2));
    g_array_remove_index(a, 1);
    printf("There are now %d items in the array\n", a->len);
    g_array_free(a, FALSE);
}
