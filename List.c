//
// Created by mustafa58 on 25.09.2022.
//

#include <stdlib.h>
#include <stdio.h>
#include "List.h"
#define ASSERT_NOT_NULL(ptr) \
            (ptr == NULL ?    \
               ({              \
                 fputs("This pointer can not be accessed !\n", stderr), \
                 abort();    \
                }) : \
               (void) 0)

struct List_T {
    unsigned int size;
    unsigned int filled;
    int list[1];
};

List_T new_List(unsigned int size)
{
    if (size == 0) size = 1;
    List_T l = malloc(sizeof(struct List_T) +
            sizeof(int) * size-1);
    l->filled = 0;
    l->size = size;
    return l;
}

void list_add(List_T l, int item)
{
    ASSERT_NOT_NULL(l);
    l->list[l->filled++] = item;
}

int list_get(List_T l, unsigned int index)
{
    ASSERT_NOT_NULL(l);
    if (index < l->size)
        return l->list[index];
    else return l->list[0];
}

int list_find(List_T l, int item) {
    int i, found = 0;
    ASSERT_NOT_NULL(l);
    for (i = 0; i < l->filled && !found; ) {
        if(l->list[i] == item)
            found = 1;
        else i++;
    }
    if (found) return i;
    return -1;
}

int list_length(List_T l) {
    ASSERT_NOT_NULL(l);
    return (int)l->filled;
}

void list_insert(List_T l, unsigned int index, int item) {
    ASSERT_NOT_NULL(l);
    for (int i = (int)l->filled; i > index; --i) {
        l->list[i] = l->list[i-1];
    }
    l->list[index] = item;
    l->filled++;
}

int list_rem(List_T l, unsigned int index) {
    ASSERT_NOT_NULL(l);
    int r = l->list[index];
    for (int i = (int)index;i < l->filled; ++i) {
        l->list[i] = l->list[i+1];
    }
    l->filled--;
    return r;
}

void del_List(List_T l)
{
    if (l == NULL) return;
    free(l);
}