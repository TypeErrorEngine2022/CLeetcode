#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct avlNode {
    int val;
    struct avlNode* left;
    struct avlNode* right;
    int height;
}avlNode;

typedef struct avltree {
    avlNode* root;
    int rotationCount; // for 341.c
}avlTree;


avlTree* createAVLTree() {
    avlTree* avl = (avlTree*)malloc(sizeof(avlTree));
    avl -> root = NULL;
    avl -> rotationCount = 0;
    return avl;
}

void _freeAVLTree(avlNode* node) {
    if (node == NULL) return;
    _freeAVLTree(node -> left);
    _freeAVLTree(node -> right);
    free(node);
}

void freeAVLTree(avlTree* avl) {
    _freeAVLTree(avl -> root);
}

avlNode* newNode(int val) {
    avlNode* node = (avlNode*)malloc(sizeof(avlNode));
    node -> val = val;
    node -> left = node -> right = NULL;
    node -> height = 0; // leaf node
    return node;
}

int height(avlNode* node) {
    // so leaf node has height 0
    if (node == NULL) return -1;

    return node -> height;
}

int getBalance(avlNode* node) {
    if (node == NULL) return 0;

    // cannot directly use node -> left -> height,
    // error when node -> left is NULL
    return height(node -> left) - height(node -> right);
}

int max(int a, int b) {
    return (a <= b)? b: a;
}

avlNode* rightRotate(avlNode* node) {
    avlNode* oriLeft = node -> left;
    node -> left = oriLeft -> right;
    oriLeft -> right = node;
    node -> height = 1 + max(height(node -> left),
                                height(node -> right));
    oriLeft -> height = 1 + max(height(oriLeft -> left),
                                    height(oriLeft -> right));
    return oriLeft;
}

avlNode* leftRotate(avlNode* node) {
    avlNode* oriRight = node -> right;
    node -> right = oriRight -> left;
    oriRight -> left = node;
    node -> height = 1 + max(height(node -> left),
                                height(node -> right));
    oriRight -> height = 1 + max(height(oriRight -> left),
                                    height(oriRight -> right));
    return oriRight;
}

avlNode* _helperInsert(avlTree* avl, avlNode* node, int val) {
    // every inserted node must be a leaf node
    if (node == NULL) 
        return newNode(val);
    else if (node -> val > val)
        node -> left = _helperInsert(avl, node -> left, val);
    else if (node -> val < val)
        node -> right = _helperInsert(avl, node -> right, val);
    else {
        printf("cannot have nodes with duplicate value %d\n", val);
        return node;
    }

    // recursion will backtrack and update all ancestors's height in this path (call stack)
    // O(logN) 
    node -> height = 1 + max(height(node -> left),
                                height(node -> right));

    int bf = getBalance(node);

    // LL
    if (bf == 2 && val < node -> left -> val) {
        avl -> rotationCount += 1;
        return rightRotate(node);
    }
    // RR
    else if (bf == -2 && val > node -> right -> val) {
        avl -> rotationCount += 1;
        return leftRotate(node);
    }
    // LR
    else if (bf == 2 && val > node -> left -> val) {
        avl -> rotationCount += 2;
        node -> left = leftRotate(node -> left); // reduce LR to LL
        return rightRotate(node);
    }
    // RL
    else if (bf == -2 && val < node -> right -> val) {
        avl -> rotationCount += 2;
        node -> right = rightRotate(node -> right); // reduce RL to RR
        return leftRotate(node);
    }

    return node;
}

void insert(avlTree* avl, int val) {
    avl -> root = _helperInsert(avl, avl -> root, val);
}

int _find(avlNode* node, int target) {
    if (node == NULL) return 0;

    if (node -> val == target)
        return 1;
    else if (node -> val > target)
        return _find(node -> left, target);
    else 
        return _find(node -> right, target);
}

int contains(avlTree* avl, int target) {
    return _find(avl -> root, target);
}

void _preorder(avlNode* node) {
    if (node == NULL) return;
    printf("%d ", node -> val);
    _preorder(node -> left);
    _preorder(node -> right);
}

void preorder(avlTree* avl) {
    _preorder(avl -> root);
}

int getRotationCount(avlTree* avl) {
    return avl -> rotationCount;
}