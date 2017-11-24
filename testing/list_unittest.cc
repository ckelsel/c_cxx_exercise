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
    List L = MakeEmpty(NULL);

    for (int i = 0; i < length; i++) {
        Insert(i, L, L);
    }
    return L;
}


TEST(List, Empty) {
    List L = MakeEmpty(NULL);
    ASSERT_TRUE(IsEmpty(L));

    Print(L);
    free(L);
}

TEST(List, InsertAndDelete) {
    List L = CreateList(10);

    Print(L);

    Delete(33, L);

    Delete(0, L);
    Delete(9, L);

    for (int i = 0; i < 10; i++) {
        Delete(i, L);
    }

    Print(L);

    free(L);
}

TEST(List, DeleteList) {
    List L = CreateList(10);
    Print(L);

    DeleteList(L);
    ASSERT_TRUE(IsEmpty(L));
    Print(L);

    free(L);
}


TEST(List, Find) {
    List L = CreateList(10);
    Print(L);

    Position current = Find(3, L);
    ASSERT_EQ(Retrieve(current), 3);

    current = Find(13, L);
    ASSERT_EQ(current, (const Position)NULL);

    Position previous = FindPrevious(3, L);
    ASSERT_EQ(Retrieve(previous), 4);

    previous = FindPrevious(33, L);
    ASSERT_EQ(previous->Next, (const Position)NULL);

    DeleteList(L);
    ASSERT_TRUE(IsEmpty(L));
    free(L);
}

TEST(List, Reverse) {
    List L = CreateList(10);
    Print(L);

    Reverse(L);
    ASSERT_EQ(Retrieve(First(L)), 0);
    
    for (int i = 2; i < 10; i++) {
        Delete(i, L);
    }

    Reverse(L);
    ASSERT_EQ(Retrieve(First(L)), 1);

    Delete(1, L);
    Reverse(L);
    ASSERT_EQ(Retrieve(First(L)), 0);

    Delete(0, L);
    Reverse(L);

    Print(L);

    DeleteList(L);
    ASSERT_TRUE(IsEmpty(L));
    free(L);
}

TEST(List, Middle) {
    List L = CreateList(0);

    // empty
    Position middle = Middle(L);
    ASSERT_EQ(middle, (const Position)NULL);

    // 9 elements
    for (int i = 0; i < 9; i++) {
        Insert(i, L, L);
    }
    middle = Middle(L);
    ASSERT_EQ(Retrieve(middle), 4);

    // 9 8 7 6 5 4 3 2 1 0
    // 10 elements
    Insert(9, L, L);
    middle = Middle(L);
    ASSERT_EQ(Retrieve(middle), 5);

    DeleteList(L);
    free(L);
}

TEST(List, IsCircle) {
    List L = CreateList(2);

    ASSERT_FALSE(!!IsCircle(L));

    L->Next->Next = L;
    ASSERT_TRUE(!!IsCircle(L));

    L->Next->Next = NULL;
    DeleteList(L);
    free(L);
}
