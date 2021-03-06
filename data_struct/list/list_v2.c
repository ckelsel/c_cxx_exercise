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
#include <stdlib.h>
#include "list.h"

struct LinkListNode {
    ElementType Element;
    Position Next;
};

List ListMakeEmpty(List L)
{
    if (L) {
        DeleteList(L);
    }

    L = (List)malloc(sizeof(struct LinkListNode));
    if (!L) {
        return NULL;
    }

    L->Next = NULL;

    return L;
}

int IsListEmpty(List L)
{
    assert(L);
    return L->Next == NULL;
}

int IsListLast(Position P, List L)
{
    assert(P);
    return P->Next == NULL;
}

Position ListFind(ElementType X, List L)
{
    assert(L);

    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }

    return P;
}

void ListDelete(ElementType X, List L)
{
   assert(L);

   Position P;

   P = ListFindPrevious(X, L);
   if (!IsListLast(P, L)) {
       Position del = P->Next;
       P->Next = del->Next;

       free(del);
   } 
}

Position ListFindPrevious(ElementType X, List L)
{
    assert(L);

    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X) {
        P = P->Next;
    }

    return P;
}

void ListInsert(ElementType X, List L, Position P)
{
    assert(L);
    assert(P);

    Position node;

    node = (Position)malloc(sizeof(struct LinkListNode));
    if (!node) {
        return;
    }

    node->Element = X;
    node->Next = P->Next;
    P->Next = node;
}

void DeleteList(List L)
{
    assert(L);

    Position P = L->Next;
    L->Next = NULL;

    while (P != NULL) {
        Position tmp = P->Next;
        free(P);
        P = tmp;
    }
}

Position ListHeader(List L)
{
    return L;
}

Position ListFirst(List L)
{
    assert(L);

    return L->Next;
}

Position ListAdvance(Position P)
{
    assert(P);
    return P->Next;
}

ElementType ListRetrieve(Position P)
{
    assert(P);
    return P->Element;
}

void ListPrint(List L)
{
    Position P = L->Next;
    while (P != NULL) {
        printf("%d ", P->Element);
        P = P->Next;
    }
    printf("\n");
}

// first 指向反转后的第一个节点
// last 指向反转后的最后一个节点
// current 指向last
void ListReverse(List L)
{
    assert(L);

    Position current = L->Next;

    Position first = L->Next;

    // mark last element
    Position last = L->Next;

    while (current && current->Next) {

        Position move = current->Next;

        // remove
        current->Next = move->Next;

        // insert
        move->Next = first;
        L->Next = move;

        // always move to last element
        current = last;
        first = move;
    }
}

// first move one
// second move two
Position ListMiddle(List L)
{
    assert(L);

    Position first;
    Position second;

    first = L->Next;
    second = L->Next;

#if 1
    while (second && second->Next && second->Next->Next) {
        first = first->Next;
        second = second->Next->Next;
    }
#else
    while (second && second->Next) {
        second = second->Next;
        if (second->Next) {
            second = second->Next;
            first = first->Next;
        }
    }
#endif
    
    return first;
}

void ListMerge(List L1, List L2)
{
}

// circle is connect to header
int IsListCircle(List L)
{
    assert(L);

    Position P = L->Next;

    while (P && P != L) {
        P = P->Next;
    }

    return P == L;
}


