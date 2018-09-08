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
#include "tree/tree.hpp"

TEST(TreeNode1_v2, MakeEmpty)
{
    InterfaceTreeNode *root = new TreeNode1_v2();

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        root->TreeInsert(j, root);
    }

    root = root->TreeMakeEmpty(root);

    ASSERT_EQ(nullptr, root);
}

TEST(TreeNode1_v2, Find)
{
    InterfaceTreeNode *root = new TreeNode1_v2();

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        root->TreeInsert(j, root);
    }

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        InterfaceTreeNode *position = root->TreeFind(j, root);
        ASSERT_EQ(position->TreeRetrieve(position), j);
    }

    root = root->TreeMakeEmpty(root);

    ASSERT_EQ(nullptr, root);
}

TEST(TreeNode1_v2, FindMin)
{
    InterfaceTreeNode *root = new TreeNode1_v2();

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        root->TreeInsert(j, root);
    }

    InterfaceTreeNode *position = root->TreeFindMin(root);
    ASSERT_EQ(position->TreeRetrieve(position), 0);

    root = root->TreeMakeEmpty(root);

    ASSERT_EQ(nullptr, root);
}

TEST(TreeNode1_v2, FindMax)
{
    InterfaceTreeNode *root = new TreeNode1_v2();

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        root->TreeInsert(j, root);
    }

    InterfaceTreeNode *position = root->TreeFindMax(root);
    ASSERT_EQ(position->TreeRetrieve(position), 49);

    root = root->TreeMakeEmpty(root);

    ASSERT_EQ(nullptr, root);
}

TEST(TreeNode1_v2, Depth)
{
    InterfaceTreeNode *root = new TreeNode1_v2();

    for (int i = 0, j = 0; i < 50; i++, j = (j + 7) % 50) {
        root->TreeInsert(j, root);
    }

    ASSERT_EQ(root->TreeDepth(root), 14);

    root = root->TreeMakeEmpty(root);

    ASSERT_EQ(nullptr, root);
}

