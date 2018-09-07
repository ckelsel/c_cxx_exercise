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
#include "tree.hpp"
#include <cassert>
#include <cstdio>
#include <cstdlib>

InterfaceTreeNode* InterfaceTreeNode::TreeMakeEmpty(InterfaceTreeNode* T)
{
    if (T) {
        TreeMakeEmpty(T->Left);
        TreeMakeEmpty(T->Right);
        free(T);
    }

    return NULL;
}

InterfaceTreeNode* InterfaceTreeNode::TreeFind(ElementType X, InterfaceTreeNode* T)
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

InterfaceTreeNode* InterfaceTreeNode::TreeFindMax(InterfaceTreeNode* T)
{
    if (T == NULL) {
        return NULL;
    }

    while (T->Right != NULL) {
        T = T->Right;
    }

    return T;
}

InterfaceTreeNode* InterfaceTreeNode::TreeFindMin(InterfaceTreeNode* T)
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

InterfaceTreeNode* InterfaceTreeNode::TreeInsert(ElementType X, InterfaceTreeNode* T)
{
    if (T == NULL) {
        T = (InterfaceTreeNode*)malloc(sizeof(InterfaceTreeNode));
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

InterfaceTreeNode* InterfaceTreeNode::TreeDelete(ElementType X, InterfaceTreeNode* T)
{
    InterfaceTreeNode* tmp;

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

ElementType InterfaceTreeNode::TreeRetrieve(InterfaceTreeNode* P)
{
   return P->Element; 
}

void InterfaceTreeNode::TreePrint(InterfaceTreeNode* T)
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

#define MAX(m, n) ((m) > (n) ? (m) : (n))
int InterfaceTreeNode::TreeDepth(InterfaceTreeNode* T)
{
    if (T == NULL) {
        return 0;
    }

    return 1 + MAX(TreeDepth(T->Left), TreeDepth(T->Right));
}
