#include <stdio.h>
#include <glib.h>
#include "../includes/func4.h"

void func4() {
    //Last, nth, and nth data
	GSList * list3 = NULL;
	list3 = g_slist_append(list3, "first");
	list3 = g_slist_append(list3, "second");
	list3 = g_slist_append(list3, "third");
	printf("The last item is '%s'\n", (char *) g_slist_last(list3)->data);
	printf("The item at index '1' is '%s'\n", (char *) g_slist_nth(list3, 1)->data);
	printf("Now the item at index '1' the easy way: '%s'\n", (char *) g_slist_nth_data(list3, 1));
	printf("And the 'next' item after first item is '%s'\n", (char *) g_slist_next(list3)->data);
	g_slist_free(list3);
}
