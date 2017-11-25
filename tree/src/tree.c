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
#include <assert.h>
#include "tree.h"

struct TreeNode {
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};

SearchTree TreeMakeEmpty(SearchTree T)
{
    if (T) {
        TreeMakeEmpty(T->Left);
        TreeMakeEmpty(T->Right);
        free(T);
    }

    return NULL;
}

Position TreeFind(ElementType X, SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->Element) {
        return TreeFind(X, T->Left);
    } else if (X > T->Element) {
        return TreeFind(X, T->Right);
    } else {
        return T;
    }
}

Position TreeFindMax(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    while (T->Right != NULL) {
        T = T->Right;
    }

    return T;
}

Position TreeFindMin(SearchTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (T->Left == NULL) {
        return T;
    } else {
        return TreeFindMin(T->Left);
    }
}

SearchTree TreeInsert(ElementType X, SearchTree T)
{
    if (T == NULL) {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL) {
            assert(0);
            return NULL;
        } else {
            T->Element = X;
            T->Left = NULL;
            T->Right = NULL;
        }
    }

    if (X < T->Element) {
        T->Left = TreeInsert(X, T->Left);
    } else if (X > T->Element) {
        T->Right = TreeInsert(X, T->Right);
    }

    return T;
}

SearchTree TreeDelete(ElementType X, SearchTree T)
{
    Position tmp;

    if (T == NULL) {
        return NULL;
    }

    if (X < T->Element) {
        T->Left = TreeDelete(X, T->Left);
    } else if (X > T->Element) {
        T->Right = TreeDelete(X, T->Right);
    } else {
        // two child
        if (T->Left != NULL && T->Right != NULL) {
            tmp = TreeFindMin(T->Right);
            T->Element = tmp->Element;
            T->Right = TreeDelete(tmp->Element, T->Right);
        } else {
            tmp = T;
            if (T->Left == NULL) {
                T = T->Right;
            } else if (T->Right == NULL) {
                T = T->Left;
            }

            free(tmp);
        }
    }

    return T;
}

ElementType TreeRetrieve(Position P)
{
   return P->Element; 
}

void TreePrint(SearchTree T)
{
    if (T == NULL) {
        return;
    }

    printf("%d ", T->Element);

    if (T->Left != NULL) {
        TreePrint(T->Left);
    }

    if (T->Right != NULL) {
        TreePrint(T->Right);
    }
    printf("\n");
}