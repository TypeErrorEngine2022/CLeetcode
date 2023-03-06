#ifndef TREENODE_H
#define TREENODE_H 
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newTree(int *val, int size) {
    if (size <= 0) return NULL;
    struct TreeNode** nodes = (struct TreeNode**)malloc(size * sizeof(struct TreeNode*));
    for (int i = 0; i < size; i++) {
        if (val[i] == NULL) {
            nodes[i] = NULL;
            continue;
        }
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 
        node -> val = val[i];
        node -> left = NULL;
        node -> right = NULL;
        nodes[i] = node;
    }
    for (int i = 0; i < size; i++) {
        if (2 * i + 1 < size) nodes[i] -> left = nodes[2 * i + 1];
        if (2 * i + 2 < size) nodes[i] -> right = nodes[2 * i + 2];
    }
    struct TreeNode* root = nodes[0];
    free(nodes);
    return root;
}

#endif