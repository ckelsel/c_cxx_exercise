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
#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

typedef int ElementType;

AvlTree AvlMakeEmpty(AvlTree T);

Position AvlFind(AvlTree T);
Position AvlFindMin(AvlTree T);
Position AvlFindMax(AvlTree T);

AvlTree AvlInsert(ElementType X, AvlTree T);

AvlTree AvlDelete(ElementType X, AvlTree T);

ElementType Retrieve(Position P);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __AVL_TREE_H__