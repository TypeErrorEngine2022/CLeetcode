/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include "TreeNodeArrayList.h"
#include "TreeNode.h"


int* rightSideView(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(101 * sizeof(int));
    *returnSize = 0;
    if (root == NULL) return returnSize;
    TreeNodeArrayList* queue = createTreeNodeArrayList(100);
    push_back(queue, root);
    int size = 1;
    while (!empty(queue)) {
        for (int i = size; i > 0; i--) {
            struct TreeNode* cur = pop_front(queue);
            if (i == 1) {
                res[*(returnSize)] = cur -> val;
                *returnSize += 1;
            }
            if (cur -> left != NULL) 
                push_back(queue, cur -> left);
            if (cur -> right != NULL) 
                push_back(queue, cur -> right);
        }
        size = getSize(queue); 
    }
    closeTreeNodeArrayList(queue); 
    return res; 
}

void solve(struct TreeNode* root, int* res, int* returnSize, int depth) {
    if (root == NULL) return;

    // traverse to right first, it is dfs
    // so when we come back to left siblings, returnSize must be >= depth + 1 
    if (depth == *returnSize) {
       res[*returnSize] = root -> val;
       *returnSize += 1;
    }

    solve(root -> right, res, returnSize, depth + 1);
    solve(root -> left, res, returnSize, depth + 1);
}

int* recursiveRightSideView(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 0;
    int* res = (int*)malloc(100 * sizeof(int));
    solve(root, res, returnSize, 0);
    return res; 
}

int main() {
    int val[7] = {1,2,3,NULL,5,NULL,4};
    printf("hi\n");
    struct TreeNode* root = newTree(val, 7);
    int returnSize;
    int* res = recursiveRightSideView(root, &returnSize);
    printf("returnSize is %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("hi\n");
        printf("%d ", res[i]);
    }

    return 0;
}