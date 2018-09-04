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

SearchTree TreeMakeEmpty(SearchTree T);

Position TreeFind(ElementType X, SearchTree T);

Position TreeFindMax(SearchTree T);

Position TreeFindMin(SearchTree T);

SearchTree TreeInsert(ElementType X, SearchTree T);

SearchTree TreeDelete(ElementType X, SearchTree T);

ElementType TreeRetrieve(Position P);

void TreePrint(SearchTree T);

int TreeDepth(SearchTree T);

#ifdef __cplusplus
}
#endif
#endif // __TREE_H__
