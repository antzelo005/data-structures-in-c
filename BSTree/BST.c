#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// Initialize BST
void BST_init(BSTree* tree) {
    *tree = NULL;
}

// Check if BST is empty
int BST_empty(BSTree tree) {
    return tree == NULL;
}

// Get data of a node
elem BST_data(BSTree node) {
    return node->data;
}

// Helper function to create a new node
static BSTNode* create_node(elem x) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a new element into BST (recursive)
int BST_insert(BSTree* tree, elem x) {
    if (BST_empty(*tree)) {
        *tree = create_node(x);
        return (*tree != NULL);
    }

    if (x < (*tree)->data) {
        return BST_insert(&((*tree)->left), x);
    } else if (x > (*tree)->data) {
        return BST_insert(&((*tree)->right), x);
    } else {
        printf("Element already exists\n");
        return 0; // Duplicate
    }
}

// Find the minimum node (helper for deletion)
static BSTNode* find_min(BSTree tree) {
    if (tree == NULL) return NULL;
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

// Delete an element from BST (recursive)
int BST_delete(BSTree* tree, elem x) {
    if (BST_empty(*tree)) {
        printf("Element not found\n");
        return 0;
    }

    if (x < (*tree)->data) {
        return BST_delete(&((*tree)->left), x);
    } else if (x > (*tree)->data) {
        return BST_delete(&((*tree)->right), x);
    } else {
        // Case 1: No children
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            free(*tree);
            *tree = NULL;
        }
        // Case 2: One child (right)
        else if ((*tree)->left == NULL) {
            BSTNode* temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        }
        // Case 3: One child (left)
        else if ((*tree)->right == NULL) {
            BSTNode* temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        }
        // Case 4: Two children
        else {
            BSTNode* temp = find_min((*tree)->right);
            (*tree)->data = temp->data;
            BST_delete(&((*tree)->right), temp->data);
        }
        return 1;
    }
}

// Search for an element in BST (recursive)
int BST_search(BSTree tree, elem x) {
    if (BST_empty(tree)) {
        return 0;
    }

    if (x < tree->data) {
        return BST_search(tree->left, x);
    } else if (x > tree->data) {
        return BST_search(tree->right, x);
    } else {
        return 1; // Found
    }
}

// In-order traversal (left, root, right)
void BST_inorder(BSTree tree) {
    if (tree != NULL) {
        BST_inorder(tree->left);
        printf("%d ", tree->data);
        BST_inorder(tree->right);
    }
}

// Pre-order traversal (root, left, right)
void BST_preorder(BSTree tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        BST_preorder(tree->left);
        BST_preorder(tree->right);
    }
}

// Post-order traversal (left, right, root)
void BST_postorder(BSTree tree) {
    if (tree != NULL) {
        BST_postorder(tree->left);
        BST_postorder(tree->right);
        printf("%d ", tree->data);
    }
}