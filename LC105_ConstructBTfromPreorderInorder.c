#include "TreeNode.h"
#include <stdio.h>

struct TreeNode* helper(int* preorder, int prestart,
                        int preEnd, 
                        int* inorder, int instart, 
                        int inEnd,
                        int* elementPos) {
    if (prestart > preEnd || instart > inEnd) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    printf("prestart: %d ", prestart);
    printf("instart: %d ", instart);
    root -> val = preorder[prestart];
    printf("root val: %d ", root -> val);
    int rootPos = elementPos[(root -> val >= 0)? 3001 + (root -> val): -1 * (root -> val)];
    int newSize = rootPos - instart; 
    printf("root pos: %d ", rootPos);
    printf("newSize: %d\n", newSize);
    root -> left = helper(preorder, prestart + 1, 
                            prestart + newSize, inorder,
                            instart, rootPos - 1,
                            elementPos);
    root -> right = helper(preorder, prestart + newSize + 1,
                            preEnd, inorder,
                            rootPos + 1, inEnd,
                            elementPos);
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    int* elementPos = (int*)malloc(6002 * sizeof(int));
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] < 0) {
            elementPos[-1 * inorder[i]] = i;
        }
        else {
            elementPos[3001 + inorder[i]] = i;
        }
    }
    struct TreeNode* root = helper(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1, elementPos);
    free(elementPos);
    return root;
}

void dfsPrint(struct TreeNode* root) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d\n", root -> val);
    dfsPrint(root -> left);
    dfsPrint(root -> right);
}

int main() {
    int pre[8] = {7,-10,-4,3,-1,2,-8,11};
    int in[8] = {-4,-10,3,-1,7,11,-8,2};
    struct TreeNode* root = buildTree(pre, 8, in, 8);
    dfsPrint(root);
    return 0;
}