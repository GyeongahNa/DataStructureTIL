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

BTreeNode* RemoveLeftSubTree(BTreeNode* bt) {

    if (bt == NULL) return NULL;
    BTreeNode* rnode = bt->left;
    bt->left = NULL;
    return rnode;
}

BTreeNode* RemoveRightSubTree(BTreeNode* bt) {

    if (bt == NULL) return NULL;
    BTreeNode* rnode = bt->right;
    bt->right = NULL;
    return rnode;
}

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub) {
    main->left = sub;
}

void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub) {
    main->right = sub;
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