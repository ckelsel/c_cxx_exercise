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

#ifndef __TREE_H__
#define __TREE_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef int ElementType;

struct TreeNode;

typedef struct TreeNode *PtrToNode;
typedef PtrToNode SearchTree;
typedef PtrToNode Position;

SearchTree MakeEmpty(SearchTree T);

Position Find(ElementType X, SearchTree T);

Position FindMax(SearchTree T);

Position FindMin(SearchTree T);

SearchTree Insert(ElementType X, SearchTree T);

SearchTree Delete(ElementType X, SearchTree T);

ElementType Retrieve(Position P);

void Print(SearchTree L);

#ifdef __cplusplus
}
#endif
#endif // __TREE_H__