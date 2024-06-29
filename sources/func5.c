#include <stdio.h>
#include <glib.h>
#include "../includes/func5.h"

typedef struct {
	char * name;
	int shoe_size;
} Person;

void func5() {
    //Working with a user-defined type
	GSList * list4 = NULL;
	Person * tom = (Person *)malloc(sizeof(Person));
	tom->name = "Tom";
	tom->shoe_size = 12;
	list4 = g_slist_append(list4, tom);
	Person * fred = g_new(Person, 1); // allocate memory for one Person struct
	fred->name = "Fred";
	fred->shoe_size = 11;
	list4 = g_slist_append(list4, fred);
	printf("Tom's shoe size is '%d'\n", ((Person *)list4->data)->shoe_size);
	printf("The last Person's name is '%s'\n", ((Person *)g_slist_last(list4)->data)->name);
	g_slist_free(list4);
	free(tom);
	g_free(fred);
}
