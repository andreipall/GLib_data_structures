#include <stdio.h>
#include <glib.h>
#include "../includes/func32.h"

static void key_d(gpointer data) {
    printf("Key %s destroyed\n", (char *) data);
}

static void value_d(gpointer data) {
    printf("Value %s destroyed\n", (char *) data);
}

void func32() {
    //Tree replace and steal
    GTree * t = g_tree_new_full((GCompareDataFunc)g_ascii_strcasecmp, NULL, (GDestroyNotify)key_d, (GDestroyNotify)value_d);
    g_tree_insert(t, "c", "Chicago");
    g_tree_insert(t, "b", "Boston");
    g_tree_insert(t, "d", "Detroit");
    printf(">Replacing 'b', should get destroy callbacks\n");
    g_tree_replace(t, "b", "Billings");
    printf(">Stealing 'b', no destroy notifications will occur\n");
    g_tree_steal(t, "b");
    printf(">Destroying entire tree now\n");
    g_tree_destroy(t);
}
