#include <stdio.h>
#include <glib.h>
#include "../includes/func2.h"

void func2() {
    //The GSList struct is used for each element in the singly-linked list.
	GSList * list1 = NULL;
	printf("The list is now %d items long\n", g_slist_length(list1));
	list1 = g_slist_append(list1, "first");
	list1 = g_slist_append(list1, "second");
	printf("The list is now %d items long\n", g_slist_length(list1));
	g_slist_free(list1);
}
