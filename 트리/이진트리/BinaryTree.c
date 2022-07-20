#include <stdlib.h>
#include "BinaryTree.h"

BTreeNode* MakeBTreeNode() {
    BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BTData GetData(BTreeNode* bt) {
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data) {
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}

void DeleteTree(BTreeNode* bt) {
    
    if (bt == NULL) return ;
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    free(bt);
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* bt) {

    DeleteTree(main->left);
    main->left = bt;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* bt) {

    DeleteTree(main->right);
    main->right = bt;
}

void PreorderTraverse(BTreeNode* bt, VisitFunc action) {

    if (bt == NULL) return ;
    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode* bt, VisitFunc action) {

    if (bt == NULL) return ;
    InorderTraverse(bt->left, action);
    action(bt->data);
    InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFunc action) {

    if (bt == NULL) return ;
    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}