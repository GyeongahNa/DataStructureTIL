#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include "BinaryTree.h"

void BSTInit(BTreeNode** pRoot);
void BSTInsert(BTreeNode** pRoot, BTData data);
BTreeNode* BSTSearch(BTreeNode* bst, BTData target);
BTreeNode* BSTRemove(BTreeNode** pRoot, BTData target);

#endif