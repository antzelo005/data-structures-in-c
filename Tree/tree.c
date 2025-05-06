#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void TR_init(tPTR* root) {
    *root = NULL;
}

int TR_empty(tPTR root) {
    return root == NULL;
}

elem TR_data(tPTR node) {
    return node->data;
}

int TR_insert_root(tPTR* root, elem x) {
    if (!TR_empty(*root)) {
        return 0; // Root already exists
    }

    tPTR newnode = (tPTR)malloc(sizeof(tNode));
    if (!newnode) {
        printf("Memory allocation failed");
        return 0;
    }

    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;

    *root = newnode;
    return 1;
}

int TR_insert_left(tPTR node, elem x) {
    if (node->left != NULL) {
        printf("Left child already exists");
        return 0;
    }

    tPTR newnode = (tPTR)malloc(sizeof(tNode));
    if (!newnode) {
        printf("Memory allocation failed");
        return 0;
    }

    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;

    node->left = newnode;
    return 1;
}

int TR_insert_right(tPTR node, elem x) {
    if (node->right != NULL) {
        printf("Right child already exists");
        return 0;
    }

    tPTR newnode = (tPTR)malloc(sizeof(tNode));
    if (!newnode) {
        printf("Memory allocation failed");
        return 0;
    }

    newnode->data = x;
    newnode->right = NULL;
    newnode->left = NULL;

    node->right = newnode;
    return 1;
}

int TR_delete_root(tPTR* root, elem* x) {
    if (TR_empty(*root)) {
        return 0; // Tree is empty
    }

    if ((*root)->left != NULL || (*root)->right != NULL) {
        printf("Node has children");
        return 0;
    }

    *x = (*root)->data;
    free(*root);
    *root = NULL;
    return 1;
}

int TR_delete_left(tPTR parent, elem* x) {
    if (parent->left == NULL) {
        return 0; // No left child
    }

    if (parent->left->left != NULL || parent->left->right != NULL) {
        printf("Node has children");
        return 0;
    }

    *x = parent->left->data;
    free(parent->left);
    parent->left = NULL;
    return 1;
}

int TR_delete_right(tPTR parent, elem* x) {
    if (parent->right == NULL) {
        return 0; // No right child
    }

    if (parent->right->left != NULL || parent->right->right != NULL) {
        printf("Node has children");
        return 0;
    }

    *x = parent->right->data;
    free(parent->right);
    parent->right = NULL;
    return 1;
}