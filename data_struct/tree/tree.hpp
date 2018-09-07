/*Copyright 2017 kunming.xie
 *
 *Licensed under the Apache License, Version 2.0 (the "License");
 *you may not use this file except in compliance with the License.
 *You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *Unless required by applicable law or agreed to in writing, software
 *distributed under the License is distributed on an "AS IS" BASIS,
 *WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *See the License for the specific language governing permissions and
 *limitations under the License.
 */

#ifndef __TREE_H__
#define __TREE_H__

typedef int ElementType;

struct InterfaceTreeNode {
    ElementType Element;
    struct InterfaceTreeNode *Left;
    struct InterfaceTreeNode *Right;

    virtual InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T) = 0;

    virtual ElementType TreeRetrieve(InterfaceTreeNode *P) = 0;

    virtual void TreePrint(InterfaceTreeNode *T) = 0;

    virtual int TreeDepth(InterfaceTreeNode *T) = 0;

    InterfaceTreeNode() : Element(0), Left(nullptr), Right(nullptr) { }
    virtual ~InterfaceTreeNode() { }
};

struct TreeNode : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T);

    ElementType TreeRetrieve(InterfaceTreeNode *P);

    void TreePrint(InterfaceTreeNode *T);

    int TreeDepth(InterfaceTreeNode *T);
};

struct TreeNode1 : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T);

    ElementType TreeRetrieve(InterfaceTreeNode *P);

    void TreePrint(InterfaceTreeNode *T);

    int TreeDepth(InterfaceTreeNode *T);
};

struct TreeNode1_v2 : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T);

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T);

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T);

    ElementType TreeRetrieve(InterfaceTreeNode *P);

    void TreePrint(InterfaceTreeNode *T);

    int TreeDepth(InterfaceTreeNode *T);
};
#endif // __TREE_H__
