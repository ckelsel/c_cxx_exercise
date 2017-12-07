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
#include "avltree.h"

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

AvlTree AvlMakeEmpty(AvlTree T)
{
    if (T != NULL) {
        AvlMakeEmpty(T->Left);
        AvlMakeEmpty(T->Right);
        free(T);
    }

    return NULL;
}

Position AvlFind(ElementType X, AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (X < T->Element) {
        return AvlFind(X, T->Left);
    } else if (X > T->Element) {
        return AvlFind(X, T->Right);
    } else {
        return T;
    }
}

Position AvlFindMin(AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }

    if (T->Left == NULL) {
        return T;
    } else {
        return AvlFindMin(T->Left);
    }
}

Position AvlFindMax(AvlTree T)
{
    if (T == NULL) {
        return NULL;
    }

    while (T->Right != NULL) {
        T = T->Right;
    }
    return T;
}

static int Height(Position P)
{
    return (P == NULL) ? -1 : P->Height;
}

static int Max(int height1, int height2)
{
    return height1 > height2 ? height1 : height2;
}

// K2, K2->Left
static Position SingleRotateWithLeft(Position K2)
{
    Position K1;

    assert(K2);
    assert(K2->Left);

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
    return K1;
}

// K1, K1->Right
static Position SingleRotateWithRight(Position K1)
{
    Position K2;

    assert(K1);
    assert(K1->Right);

    K2 = K1->Right;
    K1->Right = K2->Left;
    K2->Left = K1;

    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

    return K2;
}

static Position DoubleRotateWithLeft(Position K3)
{
    assert(K3->Left);
    assert(K3->Left->Right);

    // K1 K2
    K3->Left = SingleRotateWithRight(K3->Left);

    // K3 K2
    return SingleRotateWithLeft(K3);
}

static Position DoubleRotateWithRight(Position K1)
{
    assert(K1->Right);
    assert(K1->Right->Left);

    // K3 K2
    K1->Right = SingleRotateWithLeft(K1->Right);

    // K1 K2
    return SingleRotateWithRight(K1);
}

AvlTree AvlInsert(ElementType X, AvlTree T)
{
    if (T == NULL) {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL) {
            assert(0);
            return NULL;
        } else {
            T->Element = X;
            T->Height = 0;
            T->Left = NULL;
            T->Right = NULL;
        }
    }

    if (X < T->Element) {
        T->Left = AvlInsert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2) {
            if (X < T->Left->Element) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
    } else if (X > T->Element) {
        T->Right = AvlInsert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2) {
            if (X > T->Right->Element) {
                T = SingleRotateWithRight(T);
            } else {
                T = DoubleRotateWithRight(T);
            }
        }
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

    return T;
}

// unimplement
AvlTree AvlDelete(ElementType X, AvlTree T)
{
    return NULL;
}

ElementType AvlRetrieve(Position P)
{
    return P->Element;
}