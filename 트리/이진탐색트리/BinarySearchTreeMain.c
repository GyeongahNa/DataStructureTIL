#include <stdio.h>
// #include "BinaryTree.h"
#include "BinarySearchTree.h"

void PrintData(BTData data) {
    printf("%d ", data);
}

void PrintSearchResult(BTreeNode* sNode) {

    if (sNode == NULL) printf("찾는 결과 없음\n");
    else printf("찾는 결과 있음: %d\n", GetData(sNode));   
}

int main() {

    BTreeNode* bstRoot;
    BSTInit(&bstRoot);

    int arr[10] = {2, 10, 5, 11, 6, 3, 15, 20, 17, 8};
    for (int i=0; i<10; i++) BSTInsert(&bstRoot, arr[i]);

    InorderTraverse(bstRoot, PrintData);
    printf("\n");
    PreorderTraverse(bstRoot, PrintData);
    printf("\n\n");

    PrintSearchResult(BSTSearch(bstRoot, 15));
    free(BSTRemove(&bstRoot, 15)); //삭제
    PrintSearchResult(BSTSearch(bstRoot, 15));
    printf("\n");
    
    InorderTraverse(bstRoot, PrintData);
    printf("\n");
    PreorderTraverse(bstRoot, PrintData);
    printf("\n\n");

    return 0;
}