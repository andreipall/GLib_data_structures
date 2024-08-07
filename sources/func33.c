#include <stdio.h>
#include <glib.h>
#include "../includes/func33.h"

void func33() {
    //Looking up data
    GTree * t = g_tree_new((GCompareFunc)g_ascii_strcasecmp);
    g_tree_insert(t, "c", "Chicago");
    g_tree_insert(t, "b", "Boston");
    g_tree_insert(t, "d", "Detroit");
    printf("The data at 'b' is %s\n", (char *) g_tree_lookup(t, "b"));
    printf("%s\n",  g_tree_lookup(t, "a") ? "My goodness!" : "As expected, couldn't find 'a'");

    gpointer * key = NULL;
    gpointer * value = NULL;
    g_tree_lookup_extended(t, "c", (gpointer *)&key, (gpointer *)&value);
    printf("The data at '%s' is %s\n", (char *) key, (char *) value);
    gboolean found = g_tree_lookup_extended(t, "a", (gpointer *)&key, (gpointer *)&value);
    printf("%s\n", found ? "My goodness!" : "As expected, couldn't find 'a'");

    g_tree_destroy(t);
}
