#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinarySearchTree.h"

void BSTInit(BTreeNode** pRoot) {
    *pRoot = NULL;
}

void BSTInsert(BTreeNode** pRoot, BTData data) {

    BTreeNode* pNode = NULL;
    BTreeNode* cNode = *pRoot;

    while (cNode != NULL) {
        if (data == GetData(cNode)) return ;
        pNode = cNode;
        if (data < GetData(cNode)) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }

    BTreeNode* nNode = MakeBTreeNode();
    SetData(nNode, data);

    if (pNode == NULL) *pRoot = nNode;
    else if (data < GetData(pNode)) ChangeLeftSubTree(pNode, nNode);
    else ChangeRightSubTree(pNode, nNode);
} 

BTreeNode* BSTSearch(BTreeNode* bst, BTData target) {

    BTreeNode* cNode = bst;

    while (cNode != NULL) {
        BTData cData = GetData(cNode);
        if (target == cData) return cNode;
        if (target < cData) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }
    return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BTData target) {

    BTreeNode* pVRoot = MakeBTreeNode();
    BTreeNode* pNode = pVRoot;
    BTreeNode* cNode = *pRoot;

    ChangeRightSubTree(pVRoot, *pRoot);

    while (cNode != NULL && GetData(cNode) != target) {
        pNode = cNode;
        if (target < GetData(cNode)) cNode = GetLeftSubTree(cNode);
        else cNode = GetRightSubTree(cNode);
    }

    if (cNode == NULL) return NULL;
    BTreeNode* dNode = cNode;

    if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) { //삭제 노드가 단말 노드일 때     
        if (GetLeftSubTree(pNode) == dNode) RemoveLeftSubTree(pNode);
        else RemoveRightSubTree(pNode);
    }
    else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) { //삭제 노드가 한 개의 서브트리를 가질 때
        BTreeNode* dcNode;
        if (GetLeftSubTree(dNode) != NULL) dcNode = GetLeftSubTree(dNode);
        else dcNode = GetRightSubTree(dNode);
    
        if (GetLeftSubTree(pNode) == dNode) ChangeLeftSubTree(pNode, dcNode);
        else ChangeRightSubTree(pNode, dcNode);
    }
    else { //삭제 노드가 두 개의 서브트리를 가질 때 

        BTData rdata = GetData(dNode);
        BTreeNode* mNode = GetRightSubTree(dNode);
        BTreeNode* mpNode = dNode;

        //대체 노드 찾기
        while (GetLeftSubTree(mNode) != NULL) {
            mpNode = mNode;
            mNode = GetLeftSubTree(mNode);
        }   

        //대체
        SetData(dNode, GetData(mNode));
        dNode = mNode;
        SetData(dNode, rdata);

        //대체 노드 제거
        if (GetLeftSubTree(mpNode) == mNode) ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
    }

    if (GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);

    free(pVRoot);
    return dNode;
}
