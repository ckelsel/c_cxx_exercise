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
List MakeEmpty(List L);

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);

// success if Position->Next is not NULL
Position FindPrevious(ElementType X, List L);

// Insert X after Position P
void Insert(ElementType X, List L, Position P);

// free whose L with
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
void Reverse(List L);
void Print(List L);

#ifdef __cplusplus
}
#endif
#endif // __LIST_H__