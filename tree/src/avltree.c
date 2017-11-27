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
#include "avltree.h"

struct AvlNode {
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

AvlTree AvlMakeEmpty(AvlTree T)
{
    return NULL;
}

Position AvlFind(AvlTree T)
{
    return NULL;
}

Position AvlFindMin(AvlTree T)
{
    return NULL;
}

Position AvlFindMax(AvlTree T)
{
    return NULL;
}

AvlTree AvlInsert(ElementType X, AvlTree T)
{
    return NULL;
}

AvlTree AvlDelete(ElementType X, AvlTree T)
{
    return NULL;
}

ElementType Retrieve(Position P)
{
    return 0;
}