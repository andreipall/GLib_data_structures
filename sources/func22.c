#include <stdio.h>
#include <glib.h>
#include "../includes/func22.h"

void print(gpointer key, gpointer value, gpointer data) {
    printf("Here are some cities in %s: ", (char *) key);
    g_slist_foreach((GSList *)value, (GFunc)printf, NULL);
    printf("\n");
}

void destroy(gpointer key, gpointer value, gpointer data) {
    printf("Freeing a GSList, first item is %s\n", (char *) ((GSList *)value)->data);
    g_slist_free(value);
}

void func22() {
    //Multiple values for each key
    GHashTable * hash = g_hash_table_new(g_str_hash, g_str_equal);
    g_hash_table_insert(hash, "Texas", g_slist_append(g_hash_table_lookup(hash, "Texas"), "Austin "));
    g_hash_table_insert(hash, "Texas", g_slist_append(g_hash_table_lookup(hash, "Texas"), "Houston "));
    g_hash_table_insert(hash, "Virginia", g_slist_append(g_hash_table_lookup(hash, "Virginia"), "Richmond "));
    g_hash_table_insert(hash, "Virginia", g_slist_append(g_hash_table_lookup(hash, "Virginia"), "Keysville "));
    g_hash_table_foreach(hash, print, NULL);
    g_hash_table_foreach(hash, destroy, NULL);
    g_hash_table_destroy(hash);
}
