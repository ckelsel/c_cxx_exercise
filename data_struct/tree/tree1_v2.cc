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
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"

// 基于tree1.c修改，用时60分钟
// TreeDelete不会做
// TreeFindMin递归方式不会做

struct TreeNode {
    ElementType element;
    PtrToNode left;
    PtrToNode right;
};

// 后序遍历
SearchTree TreeMakeEmpty(SearchTree T)
{
    if (T) {
        TreeMakeEmpty(T->left);
        TreeMakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position TreeFind(ElementType X, SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->element) {
        return TreeFind(X, T->left);
    }

    if (X > T->element) {
        return TreeFind(X, T->right);
    }

    return T;
}

Position TreeFindMax(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    while (T->right != NULL) {
        T = T->right;
    }

    return T;
}

Position TreeFindMin(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (T->left != NULL) {
        return TreeFindMin(T->left);
    }

    return T;
}

// 因为需要增加节点，因此需要把节点加入树
// T->left = TreeInsert(X, T->left);
// 而不是直接返回
// return TreeInsert(X, T->left);
SearchTree TreeInsert(ElementType X, SearchTree T)
{
    if (T == NULL) {
        PtrToNode node = malloc(sizeof(struct TreeNode));
        node->element = X;
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    if (X < T->element) {
        T->left = TreeInsert(X, T->left);
    } else if (X > T->element) {
        T->right = TreeInsert(X, T->right);
    }
    return T;
}

// 删除节点
// 情况1：叶子节点
// 情况2：有一个节点
// 情况3：有两个节点, 右子树的最小节点替换当前节点, 需要遍历两次
SearchTree TreeDelete(ElementType X, SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    Position position = TreeFind(X, T);
    if (position == NULL) {
        return NULL;
    }

    if (position->left && position->right) {
        Position min = TreeFindMin(position->right);
        position->element = min->element;
        TreeDelete(min->element, min);
    } else {
        if (position->left == NULL && position->right == NULL) {
            free(position);
        } else if (position->left == NULL) {
            Position del = position;
            position = position->right;
            free(del);
        } else {
            Position del = position->left;
            position = position->left;
            free(del);
        }
    }
    return NULL;
}

ElementType TreeRetrieve(Position P)
{
    return P->element;
}

// 中序遍历
void TreePrint(SearchTree T)
{
    if (T) {
        TreePrint(T->left);
        printf("%d", T->element);
        TreePrint(T->right);
    }
}

int TreeDepth(SearchTree T)
{
}
