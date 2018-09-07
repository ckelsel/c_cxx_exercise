/*CopyRight 2017 kunming.xie
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.hpp"

// 基于tree1.c修改，用时60分钟
// TreeDelete不会做
// TreeFindMin递归方式不会做


// 后序遍历
InterfaceTreeNode *TreeNode1_v2::TreeMakeEmpty(InterfaceTreeNode * T)
{
    if (T) {
        TreeMakeEmpty(T->Left);
        TreeMakeEmpty(T->Right);
        delete T;
    }
    return NULL;
}

InterfaceTreeNode *TreeNode1_v2::TreeFind(ElementType X, InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->Element) {
        return TreeFind(X, T->Left);
    }

    if (X > T->Element) {
        return TreeFind(X, T->Right);
    }

    return T;
}

InterfaceTreeNode *TreeNode1_v2::TreeFindMax(InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    while (T->Right != NULL) {
        T = T->Right;
    }

    return T;
}

InterfaceTreeNode *TreeNode1_v2::TreeFindMin(InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    if (T->Left != NULL) {
        return TreeFindMin(T->Left);
    }

    return T;
}

// 因为需要增加节点，因此需要把节点加入树
// T->Left = TreeInsert(X, T->Left);
// 而不是直接返回
// return TreeInsert(X, T->Left);
InterfaceTreeNode *TreeNode1_v2::TreeInsert(ElementType X, InterfaceTreeNode * T)
{
    if (T == NULL) {
        TreeNode1_v2 *node = new TreeNode1_v2();
        node->Element = X;
        return node;
    }

    if (X < T->Element) {
        T->Left = TreeInsert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = TreeInsert(X, T->Right);
    }
    return T;
}

// 删除节点
// 情况1：叶子节点
// 情况2：有一个节点
// 情况3：有两个节点, 右子树的最小节点替换当前节点, 需要遍历两次
// NOTE: 跟Find的流程一样
InterfaceTreeNode *TreeNode1_v2::TreeDelete(ElementType X, InterfaceTreeNode * T)
{
    if (T == NULL) {
        return NULL;
    }

    InterfaceTreeNode *position = TreeFind(X, T);
    if (position == NULL) {
        return NULL;
    }

    if (position->Left && position->Right) {
        InterfaceTreeNode *min = TreeFindMin(position->Right);
        position->Element = min->Element;
        TreeDelete(min->Element, min);
    } else {
        if (position->Left == NULL && position->Right == NULL) {
            delete position;
        } else if (position->Left == NULL) {
            InterfaceTreeNode *del = position;
            position = position->Right;
            delete del;
        } else {
            InterfaceTreeNode *del = position->Left;
            position = position->Left;
            delete del;
        }
    }
    return NULL;
}

ElementType TreeNode1_v2::TreeRetrieve(InterfaceTreeNode *P)
{
    return P->Element;
}

// 中序遍历
void TreeNode1_v2::TreePrint(InterfaceTreeNode *T)
{
    if (T) {
        TreePrint(T->Left);
        printf("%d", T->Element);
        TreePrint(T->Right);
    }
}

int TreeNode1_v2::TreeDepth(InterfaceTreeNode *T)
{
    return 0;
}

