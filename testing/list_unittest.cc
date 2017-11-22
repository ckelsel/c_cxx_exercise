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

TEST(List, Empty) {
    List L = (List)malloc(sizeof(struct LinkListNode));

    MakeEmpty(L);
    ASSERT_TRUE(IsEmpty(L));

    Print(L);
    free(L);
}

TEST(List, InsertAndDelete) {
    List L = (List)malloc(sizeof(struct LinkListNode));
    MakeEmpty(L);

    for (int i = 0; i < 10; i++) {
        Insert(i, L, L);
    }

    Print(L);

    Delete(33, L);

    for (int i = 0; i < 10; i++) {
        Delete(i, L);
    }

    Print(L);

    free(L);
}

TEST(List, DeleteList) {
    List L = (List)malloc(sizeof(struct LinkListNode));
    MakeEmpty(L);

    for (int i = 0; i < 10; i++) {
        Insert(i, L, L);
    }
    Print(L);

    DeleteList(L);
    Print(L);

    free(L);
}


TEST(List, Find) {
    List L = (List)malloc(sizeof(struct LinkListNode));
    MakeEmpty(L);

    for (int i = 0; i < 10; i++) {
        Insert(i, L, L);
    }
    Print(L);

    Position current = Find(3, L);
    ASSERT_EQ(current->Element, 3);

    current = Find(13, L);
    ASSERT_EQ(current, (const Position)NULL);

    Position previous = FindPrevious(3, L);
    ASSERT_EQ(previous->Element, 4);

    previous = FindPrevious(33, L);
    ASSERT_EQ(previous, (const Position)NULL);

    DeleteList(L);
    free(L);
}