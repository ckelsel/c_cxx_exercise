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

SearchTree MakeEmpty(SearchTree T)
{
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    return NULL;
}

Position FindMax(SearchTree T)
{
    return NULL;
}

Position FindMin(SearchTree T)
{
    return NULL;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    return NULL;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    return NULL;
}

ElementType Retrieve(Position P)
{
   return 0; 
}

void Print(SearchTree L)
{
    
}