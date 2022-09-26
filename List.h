//
// Created by mustafa58 on 25.09.2022.
//

#ifndef LISTS_LIST_H
#define LISTS_LIST_H

typedef struct List_T *List_T;
List_T new_List(unsigned int size);
void   list_add(List_T l, int item);
int    list_rem(List_T l, unsigned int index);
int    list_get(List_T l, unsigned int index);
int    list_find(List_T l, int item);
int    list_length(List_T l);
void   list_insert(List_T l, unsigned int index, int item);
void   del_List(List_T p);

#endif //LISTS_LIST_H
