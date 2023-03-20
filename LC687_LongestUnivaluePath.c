#include "TreeNode.h"

int max(int a, int b) {
    return (a >= b)? a : b;
}

int dfs(struct TreeNode* root, int* res) {
    if (root == NULL) return 0;

    int lvalid = (root -> left != NULL);
    int rvalid = (root -> right != NULL);

    int l = dfs(root -> left, res);
    int r = dfs(root -> right, res);

    int split = 0;
    if (lvalid && rvalid && root -> left -> val == root -> right -> val &&
            root -> val == root -> left -> val)
        split = l + 1 + r + 1; // each child contributes one edge

    // choose one side with same value
    int noSplit = 0;
    if (lvalid && root -> left -> val == root -> val)
        noSplit = l + 1;
    if (rvalid && root -> right -> val == root -> val)
        noSplit = max(noSplit, r + 1); 
    
    *res = max(max(noSplit, split), *res);
    
    return noSplit;
}
    
int longestUnivaluePath(struct TreeNode* root){
    int res = 0;
    dfs(root, &res);
    return res;
}