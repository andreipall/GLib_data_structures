#include <stdio.h>
#include <glib.h>
#include "../includes/func3.h"

void func3() {
    //Removing duplicate items
	GSList * list2 = NULL;
	list2 = g_slist_append(list2, "first");
	list2 = g_slist_append(list2, "second");
	list2 = g_slist_append(list2, "second");
	list2 = g_slist_append(list2, "third");
	list2 = g_slist_append(list2, "third");
	printf("The list is now %d items long\n", g_slist_length(list2));
	list2 = g_slist_remove(list2, "second");
	list2 = g_slist_remove_all(list2, "third");
	printf("The list is now %d items long\n", g_slist_length(list2));
	g_slist_free(list2);
}
