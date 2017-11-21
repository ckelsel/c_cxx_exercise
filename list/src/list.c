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
#include "list.h"

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    return NULL;
}

int IsEmpty(List L)
{
    return 0;
}

int IsLast(List L)
{
    return 0;    
}

Position Find(ElementType X, List L)
{
    return NULL;
}

void Delete(ElementType X, List L)
{
    
}

Position FindPrevious(ElementType X, List L)
{
    return NULL;
}

void Insert(ElementType X, List L, Position P)
{
    
}

void DeleteList(List L)
{
    
}

Position Header(List L)
{
    return NULL;
}

Position First(List L)
{
    return NULL;
}

Position Advance(Position P)
{
    return NULL;
}

Position Retrieve(Position P)
{
    return NULL;
}
