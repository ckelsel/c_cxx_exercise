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

#ifndef __LIST_H__
#define __LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef int ElementType;

struct LinkListNode;

typedef struct LinkListNode *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// if L is NULL, then create a empty List With header
// if L is not NULL, then free it. Then create a empty List With header
List ListMakeEmpty(List L);

int IsListEmpty(List L);
int IsListLast(Position P, List L);
Position ListFind(ElementType X, List L);
void ListDelete(ElementType X, List L);

// success if Position->Next is not NULL
Position ListFindPrevious(ElementType X, List L);

// Insert X after Position P
void ListInsert(ElementType X, List L, Position P);

// free whose L without header
void DeleteList(List L);
Position ListHeader(List L);
Position ListFirst(List L);
Position ListAdvance(Position P);
ElementType ListRetrieve(Position P);
void ListReverse(List L);

// get middle position
// return NULL if L is empty else return middle positon
Position ListMiddle(List L);

// merge L2 into L1
void ListMerge(List L1, List L2);

// return TRUE if circle
int IsListCircle(List L);


void ListPrint(List L);

#ifdef __cplusplus
}
#endif
#endif // __LIST_H__