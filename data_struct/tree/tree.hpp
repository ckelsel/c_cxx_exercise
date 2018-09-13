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

#ifndef __DATA_STRUCT_TREE_TREE_HPP__
#define __DATA_STRUCT_TREE_TREE_HPP__

typedef int ElementType;

struct InterfaceTreeNode {
    ElementType Element = 0;
    struct InterfaceTreeNode *Left = nullptr;
    struct InterfaceTreeNode *Right = nullptr;

    virtual InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T) = 0;

    virtual InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T) = 0;

    virtual ElementType TreeRetrieve(InterfaceTreeNode *P) = 0;

    virtual void TreePrint(InterfaceTreeNode *T) = 0;

    virtual int TreeDepth(InterfaceTreeNode *T) = 0;

    virtual void InOrder(InterfaceTreeNode *T) = 0;

    virtual void PreOrder(InterfaceTreeNode *T) = 0;

    virtual void PostOrder(InterfaceTreeNode *T) = 0;

    InterfaceTreeNode() = default;
    virtual ~InterfaceTreeNode() = default;

    InterfaceTreeNode(const InterfaceTreeNode &) = delete;
    InterfaceTreeNode& operator=(const InterfaceTreeNode &) = delete;

    InterfaceTreeNode(InterfaceTreeNode &&) = delete;
    InterfaceTreeNode& operator=(InterfaceTreeNode &&) = delete;
};

struct TreeNode : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T) override;

    ElementType TreeRetrieve(InterfaceTreeNode *P) override;

    void TreePrint(InterfaceTreeNode *T) override;

    int TreeDepth(InterfaceTreeNode *T) override;

    void InOrder(InterfaceTreeNode *T) override { }

    void PreOrder(InterfaceTreeNode *T) override { }

    void PostOrder(InterfaceTreeNode *T) override { }
};

struct TreeNode1 : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T) override;

    ElementType TreeRetrieve(InterfaceTreeNode *P) override;

    void TreePrint(InterfaceTreeNode *T) override;

    int TreeDepth(InterfaceTreeNode *T) override;

    void InOrder(InterfaceTreeNode *T) override { }

    void PreOrder(InterfaceTreeNode *T) override { }

    void PostOrder(InterfaceTreeNode *T) override { }
};

struct TreeNode1_v2 : public InterfaceTreeNode {
    InterfaceTreeNode *TreeMakeEmpty(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFind(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMax(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeFindMin(InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeInsert(ElementType X, InterfaceTreeNode * T) override;

    InterfaceTreeNode *TreeDelete(ElementType X, InterfaceTreeNode * T) override;

    ElementType TreeRetrieve(InterfaceTreeNode *P) override;

    void TreePrint(InterfaceTreeNode *T) override;

    int TreeDepth(InterfaceTreeNode *T) override;

    void InOrder(InterfaceTreeNode *T) override { }

    void PreOrder(InterfaceTreeNode *T) override { }

    void PostOrder(InterfaceTreeNode *T) override { }
};

#endif //__DATA_STRUCT_TREE_TREE_HPP__

