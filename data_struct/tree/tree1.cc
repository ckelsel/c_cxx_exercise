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

// 用时30分钟
// 放空的都不会做

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
        if (T->left && T->right) {
            free(T);
            return NULL;
        }
    }
    return T;
}

Position TreeFind(ElementType X, SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->element) {
        TreeFind(T->left);
    }

    if (X > T->element) {
        TreeFind(T->right);
    }

    return T;
}

Position TreeFindMax(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    Position position;
    while (T->right != NULL) {
        position = T->right;
    }

    return position;
}

Position TreeFindMin(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    Position position;
    while (T->left != NULL) {
        position = T->left;
    }

    return position;
}

SearchTree TreeInsert(ElementType X, SearchTree T)
{

}

SearchTree TreeDelete(ElementType X, SearchTree T)
{

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
