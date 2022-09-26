//
// Created by mustafa58 on 25.09.2022.
//
#define CALL test
#include "test.h"

#ifndef __EXCLUDED__
#include <assert.h>
#include <stdlib.h>
#include "utils.h"
#include "List.h"

PRIVATE List_T list;
PRIVATE inline void assertIndex(int index, int expect) {
    assert(list_get(list, index) == expect);
}
#endif//__EXCLUDED__

TEST(canCreate_Destroy, {
    list = new_List(50);
    assert(list != NULL);
    del_List(list);
})

TEST(canSaveOneItem, {
    list = new_List(50);
    list_add(list, 123);
    assertIndex(0, 123);
    del_List(list);
})

TEST(canSaveTwoItems, {
    list = new_List(50);
    list_add(list, 123);
    list_add(list, 456);
    assertIndex(0, 123);
    assertIndex(1, 456);
})

TEST(canShowLength, {
    assert(list_length(list) == 2);
})

TEST(canInsertMiddle, {
    list_insert(list, (unsigned int) 0, 999);
    assertIndex(0, 999);
    assertIndex(1, 123);
    assertIndex(2, 456);
    assert(list_length(list) == 3);
})

TEST(canSearchInList, {
    assertIndex(list_find(list, 123), 123);
})

TEST(canRemMiddle, {
    list_rem(list, 0);
    assertIndex(0, 123);
    assertIndex(1, 456);
    assert(list_length(list) == 2);
})

TEST(canDestroy, {
    del_List(list);
})