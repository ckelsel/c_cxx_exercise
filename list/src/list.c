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

List MakeEmpty(List L)
{
    assert(L);
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    assert(L);
    return L->Next == NULL;
}

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

Position Find(ElementType X, List L)
{
    assert(L);

    List iter = L;

    while (iter->Next) {
        iter = iter->Next;

        if (iter->Element == X) {
            return iter;
        }
    }

    return NULL;
}

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

    return NULL;
}

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