#include "TreeNode.h"
#include <stdio.h>

int max(int a, int b) {
    return (a >= b)? a : b;
}

int dfs(struct TreeNode* root, int* res) {
    if (root == NULL) return 0;

    // not allow to split  
    int l = dfs(root -> left, res);
    int r = dfs(root -> right, res);
    // do not count negative children
    int singleSide = root -> val + max(max(l, r), 0);

    // allow to split 
    // left child(no split) -> parent -> right child(no split)
    int split = root -> val + l + r;

    // even if all nodes are negative
    // the least negative one will be recorded 
    *res = max(max(split, singleSide), *res);

    // parent can concatenate this path
    return singleSide;
}

int maxPathSum(struct TreeNode* root){
    if (root == NULL) return 0;
    int res = -2000;
    dfs(root, &res);
    return res; 
}