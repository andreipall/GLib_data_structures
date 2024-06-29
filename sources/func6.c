#include <stdio.h>
#include <glib.h>
#include "../includes/func6.h"

void func6() {
    //Combining, reversing, and all that
    GSList * list1 = NULL;
    list1 = g_slist_append(list1, "first");
    list1 = g_slist_append(list1, "second");
    GSList * list2 = NULL;
    list2 = g_slist_append(list2, "third");
    list2 = g_slist_append(list2, "fourth");
    GSList * both = g_slist_concat(list1, list2);
    printf("The third item in the concatenated list is '%s'\n", g_slist_nth_data(both, 2));
    GSList * reversed = g_slist_reverse(both);
    printf("The first item in the reversed list is '%s'\n", reversed->data);
    g_slist_free(reversed);
}
