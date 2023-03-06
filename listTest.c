#include "TreeNodeArrayList.h"
#include "TreeNode.h"
#include <stdio.h>

void dfsPrint(struct TreeNode* root, TreeNodeArrayList* list) {
    if (root != NULL) {
        printf("%d\n", root -> val);
        push_back(list, root);
    }
    if (root -> left != NULL) dfsPrint(root -> left, list);
    if (root -> right != NULL) dfsPrint(root -> right, list);
}

int main() {
    int val[7] = {1,2,3,NULL,5,NULL,4};
    TreeNodeArrayList* list = createTreeNodeArrayList(5);
    struct TreeNode* root = newTree(val, 7);
    dfsPrint(root, list);
    printTreeNodeArrayList(list); 
    return 0; 
}

