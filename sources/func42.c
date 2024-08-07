#include <stdio.h>
#include <glib.h>
#include "../includes/func42.h"

typedef struct {
    char * name;
    int priority;
} Task;

static Task * make_task(char * name, int priority) {
    Task * t = g_new(Task, 1);
    t->name = name;
    t->priority = priority;
    return t;
}

static void prt(gpointer item) {
    printf("%s   ", ((Task *)item)->name);
}

static gint sorter(gconstpointer a, gconstpointer b, gpointer data) {
    return ((Task *)a)->priority - ((Task *)b)->priority;
}

void func42() {
    //Sorting queues
    GQueue * q = g_queue_new();
    g_queue_push_tail(q, make_task("Reboot server", 2));
    g_queue_push_tail(q, make_task("Pull cable", 2));
    g_queue_push_tail(q, make_task("Nethack", 1));
    g_queue_push_tail(q, make_task("New monitor", 3));
    printf("Original queue: ");
    g_queue_foreach(q, (GFunc)prt, NULL);
    g_queue_sort(q, (GCompareDataFunc)sorter, NULL);
    printf("\nSorted queue: ");
    g_queue_foreach(q, (GFunc)prt, NULL);
    printf("\n");
    g_queue_free(q);
}
