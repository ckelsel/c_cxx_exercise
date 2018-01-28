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
#include "tree/tree.h"

TEST(TREE, MakeEmpty)
{
    SearchTree T = TreeMakeEmpty(NULL);

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        T = TreeInsert(j, T);
    }

    for (int i = 0; i < 50; i++) {
        Position P = TreeFind(i, T);
        ASSERT_NE(P, (const Position)NULL);
        ASSERT_EQ(TreeRetrieve(P), i);
    }

    for (int i = 0; i < 50; i += 2 ) {
        T = TreeDelete(i, T);
    }

    for (int i = 1; i < 50; i += 2) {
        Position P = TreeFind(i, T);
        ASSERT_NE(P, (const Position)NULL);
        ASSERT_EQ(TreeRetrieve(P), i);
    }

    for (int i = 0; i < 50; i += 2) {
        Position P = TreeFind(i, T);
        ASSERT_EQ(P, (const Position)NULL);
    }

    ASSERT_EQ(TreeRetrieve(TreeFindMax(T)), 49);
    ASSERT_EQ(TreeRetrieve(TreeFindMin(T)), 1);
}
