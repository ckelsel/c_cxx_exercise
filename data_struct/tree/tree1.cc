/* CopyRight 2017 kunming.xie
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
#include "tree.hpp"
#include <cassert>
#include <cstdio>
#include <cstdlib>

// 用时30分钟
// 放空的都不会做

// 后序遍历
InterfaceTreeNode * TreeNode1::TreeMakeEmpty(InterfaceTreeNode * T)
{
    if (T) {
        TreeMakeEmpty(T->Left);
        TreeMakeEmpty(T->Right);
        if (T->Left && T->Right) {
            delete T;
            return NULL;
        }
    }
    return T;
}

InterfaceTreeNode * TreeNode1::TreeFind(ElementType X, InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->Element) {
        TreeFind(X, T->Left);
    }

    if (X > T->Element) {
        TreeFind(X, T->Right);
    }

    return T;
}

InterfaceTreeNode * TreeNode1::TreeFindMax(InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    InterfaceTreeNode * position;
    while (T->Right != NULL) {
        position = T->Right;
    }

    return position;
}

InterfaceTreeNode * TreeNode1::TreeFindMin(InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    InterfaceTreeNode * position;
    while (T->Left != NULL) {
        position = T->Left;
    }

    return position;
}

InterfaceTreeNode * TreeNode1::TreeInsert(ElementType X, InterfaceTreeNode * T)
{
    return NULL;
}

InterfaceTreeNode * TreeNode1::TreeDelete(ElementType X, InterfaceTreeNode * T)
{
    return NULL;
}

ElementType TreeNode1::TreeRetrieve(InterfaceTreeNode * P)
{
    return P->Element;
}

// 中序遍历
void TreeNode1::TreePrint(InterfaceTreeNode * T)
{
    if (T) {
        TreePrint(T->Left);
        printf("%d", T->Element);
        TreePrint(T->Right);
    }
}

int TreeNode1::TreeDepth(InterfaceTreeNode * T)
{
    return 0;
}

