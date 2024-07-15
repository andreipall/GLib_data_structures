#include <stdio.h>
#include <glib.h>
#include "../includes/func1.h"

void func1() {
    //The GList struct is used for each element in a doubly-linked list.
	GList * list = NULL;
	list = g_list_append(list, "Hello world!");
	printf("The first item is '%s'\n", (char *) g_list_first(list)->data);
	g_list_free(list);
}
