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
#include "list.h"

struct LinkListNode {
    ElementType Element;
    Position Next;
};

#define FIX_MY_IMPLEMENT 1

#if FIX_MY_IMPLEMENT
// Q1: Delete List if not NULL
List MakeEmpty(List L)
{
    if (L) {
        DeleteList(L);
    }

    L = (List) malloc(sizeof(struct LinkListNode));
    if (!L) {
        return NULL;
    }

    L->Next = NULL;
    return L;
}
#else // FIX_MY_IMPLEMENT
List MakeEmpty(List L)
{
    if (L) {
        DeleteList(L);
    }

    L = (List) malloc(sizeof(struct LinkListNode));
    if (!L) {
        return NULL;
    }

    L->Next = NULL;
    return L;
}
#endif // FIX_MY_IMPLEMENT

int IsEmpty(List L)
{
    assert(L);
    return L->Next == NULL;
}

#if FIX_MY_IMPLEMENT
// compare last node with P
int IsLast(Position P, List L)
{
    assert(L);
    assert(P);

    // pointer to header
    List iter = L;

    while (iter->Next) {
        iter = iter->Next;
    }
    
    return P == iter;    
}
#else // FIX_MY_IMPLEMENT
// assert P is in L already
// if P is last that p->Next must be NULL
int IsLast(Position P, List L)
{
    return P->Next == NULL;
}
#endif  // FIX_MY_IMPLEMENT

#if FIX_MY_IMPLEMENT
// logic is not clear
Position Find(ElementType X, List L)
{
    assert(L);

    List iter = L;

    // 1. check if exist
    while (iter->Next) {
        // 2. get node
        iter = iter->Next;

        // 3. check equal
        if (iter->Element == X) {
            return iter;
        }
    }

    return NULL;
}
#else // FIX_MY_IMPLEMENT
Position Find(ElementType X, List L)
{
    Position P = L->Next;

    // FIXME: learn
    // 1. check exist and element
    while (P != NULL && P->Element != X) {
        // 2. get next node
        P = P->Next;
    }

    return P;
}
#endif // FIX_MY_IMPLEMENT


#if FIX_MY_IMPLEMENT
void Delete(ElementType X, List L)
{
    assert(L);

    // pointer to header
    List iter = L;
    
    while (iter->Next) {
        List find = iter->Next;
        if (find->Element == X) {
            // remove
            iter->Next = find->Next;

            // free resource
            free(find);
            break;
        }

        iter = iter->Next;
    }
}
#else // FIX_MY_IMPLEMENT
void Delete(ElementType X, List L)
{
    Position P;

    P = FindPrevious(X, L);
    if (!IsLast(P, L)) {
        Position del = P->Next;

        P->Next = del->Next;

        free(del);
    }
}
#endif // FIX_MY_IMPLEMENT

// success if !IsLast(FindPrevious);
#if FIX_MY_IMPLEMENT
Position FindPrevious(ElementType X, List L)
{
    assert(L);

    List iter = L;

    while (iter->Next) {
        if (iter->Next->Element == X) {
            return iter;
        }

        iter = iter->Next;
    }

    return iter;
}
#else // FIX_MY_IMPLEMENT
// if we find X, then previous node->Next must not be NULL
Position FindPrevious(ElementType X, List L)
{
    Position P;

    // 1. pointer to header
    P = L;

    // 2. check next node
    while (P->Next != NULL && P->Next->Element != X) {
        // 3. get next node
        P = P->Next;
    }

    return P;
}
#endif // FIX_MY_IMPLEMENT

#if FIX_MY_IMPLEMENT
void Insert(ElementType X, List L, Position P)
{
    assert(L);
    assert(P);

    Position node = (Position)malloc(sizeof(struct LinkListNode));
    if (!node) {
        assert(0);
        return;
    }
    node->Element = X;

    List iter = L;

    // compare header
    while (iter) {
        if (iter == P) {
            node->Next = iter->Next;
            iter->Next = node;
            break;
        }

        iter = iter->Next;
    }
}
#else // FIX_MY_IMPLEMENT
void Insert(ElementType X, List L, Position P)
{
    Position node;

    node = (Position)malloc(sizeof(struct LinkListNode));
    if (!node) {
        return;
    }
    node->Element = X;

    node->Next = P->Next;
    P->Next = node;
}
#endif // FIX_MY_IMPLEMENT

#if FIX_MY_IMPLEMENT
// FIXME: L->Next = NULL;
void DeleteList(List L)
{
    assert(L);

    List iter = L;

    while (iter->Next) {
        // get item
        List delete = iter->Next;

        // remove
        iter->Next = delete ->Next;
        
        free(delete);
    }
}
#else // FIX_MY_IMPLEMENT
void DeleteList(List L)
{
    Position P;

    P = L->Next;
    L->Next = NULL;

    while (P != NULL) {
        Position tmp = P->Next;
        free(P);
        P = tmp;
    }
}
#endif // FIX_MY_IMPLEMENT

Position Header(List L)
{
    assert(L);
    return L;
}

Position First(List L)
{
    assert(L);
    return L->Next;
}

Position Advance(Position P)
{
    assert(P);
    return P->Next;
}

ElementType Retrieve(Position P)
{
    assert(P);
    return P->Element;
}

void Print(List L)
{
    assert(L);

    List iter = L;

    printf("element: ");
    while (iter->Next) {
        iter = iter->Next;
        printf("%d ", iter->Element);
    }
    printf("\n");
}