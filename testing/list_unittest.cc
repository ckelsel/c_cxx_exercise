/* Copyright 2017 kunming.xie
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gtest/gtest.h"
#include "list.h"


struct LinkListNode {
    ElementType Element;
    Position Next;
};

List CreateList(int length) {
    List L = ListMakeEmpty(NULL);

    for (int i = 0; i < length; i++) {
        ListInsert(i, L, L);
    }
    return L;
}


TEST(List, Empty) {
    List L = ListMakeEmpty(NULL);
    ASSERT_TRUE(IsListEmpty(L));

    ListPrint(L);
    free(L);
}

TEST(List, InsertAndDelete) {
    List L = CreateList(10);

    ListPrint(L);

    ListDelete(33, L);

    ListDelete(0, L);
    ListDelete(9, L);

    for (int i = 0; i < 10; i++) {
        ListDelete(i, L);
    }

    ListPrint(L);

    free(L);
}

TEST(List, DeleteList) {
    List L = CreateList(10);
    ListPrint(L);

    DeleteList(L);
    ASSERT_TRUE(IsListEmpty(L));
    ListPrint(L);

    free(L);
}


TEST(List, Find) {
    List L = CreateList(10);
    ListPrint(L);

    Position current = ListFind(3, L);
    ASSERT_EQ(ListRetrieve(current), 3);

    current = ListFind(13, L);
    ASSERT_EQ(current, (const Position)NULL);

    Position previous = ListFindPrevious(3, L);
    ASSERT_EQ(ListRetrieve(previous), 4);

    previous = ListFindPrevious(33, L);
    ASSERT_EQ(ListAdvance(previous), (const Position)NULL);

    DeleteList(L);
    ASSERT_TRUE(IsListEmpty(L));
    free(L);
}

TEST(List, ListReverse) {
    List L = CreateList(10);
    ListPrint(L);

    ListReverse(L);
    ASSERT_EQ(ListRetrieve(ListFirst(L)), 0);
    
    for (int i = 2; i < 10; i++) {
        ListDelete(i, L);
    }

    ListReverse(L);
    ASSERT_EQ(ListRetrieve(ListFirst(L)), 1);

    ListDelete(1, L);
    ListReverse(L);
    ASSERT_EQ(ListRetrieve(ListFirst(L)), 0);

    ListDelete(0, L);
    ListReverse(L);

    ListPrint(L);

    DeleteList(L);
    ASSERT_TRUE(IsListEmpty(L));
    free(L);
}

TEST(List, ListMiddle) {
    List L = CreateList(0);

    // empty
    Position middle = ListMiddle(L);
    ASSERT_EQ(middle, (const Position)NULL);

    // 9 elements
    for (int i = 0; i < 9; i++) {
        ListInsert(i, L, L);
    }
    middle = ListMiddle(L);
    ASSERT_EQ(ListRetrieve(middle), 4);

    // 9 8 7 6 5 4 3 2 1 0
    // 10 elements
    ListInsert(9, L, L);
    middle = ListMiddle(L);
    ASSERT_EQ(ListRetrieve(middle), 5);

    DeleteList(L);
    free(L);
}

TEST(List, IsListCircle) {
    List L = CreateList(1);

    ASSERT_FALSE(!!IsListCircle(L));

    L->Next->Next = L;
    ASSERT_TRUE(!!IsListCircle(L));

    L->Next->Next = NULL;
    DeleteList(L);
    free(L);
}
