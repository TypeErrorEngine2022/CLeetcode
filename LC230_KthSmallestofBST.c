#include <stdio.h>
#include "TreeNode.h"

int kthSmallest(struct TreeNode* root, int k){
    int res = 0;
    int order = 0;
    solve(root, &res, k, &order);
    return res;
}

int solve(struct TreeNode* root, int* res, int k, int* order) {
    if (root == NULL) return 0;

    int flag = solve(root -> left, res, k, order);
    if (flag) return 1;
    *order += 1;
    if (*order == k) {
        *res = root -> val;
        return;
    }
    solve(root -> right, res, k, order);
}