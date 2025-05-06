#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

// Helper function to get height of a node
static int height(AVLTree node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// Helper function to get avl_maximum of two integers
static int avl_max(int a, int b) {
    return (a > b) ? a : b;
}

// Helper function to create a new node
static AVLTree create_node(elem x) {
    AVLTree newNode = (AVLTree)malloc(sizeof(AVLNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

// Right rotation
static AVLTree right_rotate(AVLTree y) {
    AVLTree x = y->left;
    AVLTree T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = avl_max(height(y->left), height(y->right)) + 1;
    x->height = avl_max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotation
static AVLTree left_rotate(AVLTree x) {
    AVLTree y = x->right;
    AVLTree T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = avl_max(height(x->left), height(x->right)) + 1;
    y->height = avl_max(height(y->left), height(y->right)) + 1;

    return y;
}

// Get balance factor of a node
static int get_balance(AVLTree node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// Initialize AVL tree
void AVL_init(AVLTree* tree) {
    *tree = NULL;
}

// Check if tree is empty
int AVL_empty(AVLTree tree) {
    return tree == NULL;
}

// Get data from node
elem AVL_data(AVLTree node) {
    return node->data;
}

// Insert a node into AVL tree
int AVL_insert(AVLTree* tree, elem x) {
    // Perform normal BST insertion
    if (*tree == NULL) {
        *tree = create_node(x);
        return (*tree != NULL);
    }

    if (x < (*tree)->data) {
        if (!AVL_insert(&((*tree)->left), x))
            return 0;
    } else if (x > (*tree)->data) {
        if (!AVL_insert(&((*tree)->right), x))
            return 0;
    } else {
        // Duplicate values not allowed
        return 0;
    }

    // Update height of this ancestor node
    (*tree)->height = 1 + avl_max(height((*tree)->left), height((*tree)->right));

    // Get the balance factor
    int balance = get_balance(*tree);

    // Left Left Case
    if (balance > 1 && x < (*tree)->left->data)
        *tree = right_rotate(*tree);

    // Right Right Case
    else if (balance < -1 && x > (*tree)->right->data)
        *tree = left_rotate(*tree);

    // Left Right Case
    else if (balance > 1 && x > (*tree)->left->data) {
        (*tree)->left = left_rotate((*tree)->left);
        *tree = right_rotate(*tree);
    }

    // Right Left Case
    else if (balance < -1 && x < (*tree)->right->data) {
        (*tree)->right = right_rotate((*tree)->right);
        *tree = left_rotate(*tree);
    }

    return 1;
}

// Find the node with minimum value
static AVLTree min_value_node(AVLTree node) {
    AVLTree current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node from AVL tree
int AVL_delete(AVLTree* tree, elem x) {
    if (*tree == NULL)
        return 0;

    if (x < (*tree)->data) {
        if (!AVL_delete(&((*tree)->left), x))
            return 0;
    } else if (x > (*tree)->data) {
        if (!AVL_delete(&((*tree)->right), x))
            return 0;
    } else {
        // Node with only one child or no child
        if ((*tree)->left == NULL || (*tree)->right == NULL) {
            AVLTree temp = (*tree)->left ? (*tree)->left : (*tree)->right;

            // No child case
            if (temp == NULL) {
                temp = *tree;
                *tree = NULL;
            } else {
                // One child case
                **tree = *temp; // Copy the contents
            }
            free(temp);
        } else {
            // Node with two children
            AVLTree temp = min_value_node((*tree)->right);
            (*tree)->data = temp->data;
            AVL_delete(&((*tree)->right), temp->data);
        }
    }

    // If the tree had only one node then return
    if (*tree == NULL)
        return 1;

    // Update height
    (*tree)->height = 1 + avl_max(height((*tree)->left), height((*tree)->right));

    // Get balance factor
    int balance = get_balance(*tree);

    // Left Left Case
    if (balance > 1 && get_balance((*tree)->left) >= 0)
        *tree = right_rotate(*tree);

    // Left Right Case
    else if (balance > 1 && get_balance((*tree)->left) < 0) {
        (*tree)->left = left_rotate((*tree)->left);
        *tree = right_rotate(*tree);
    }

    // Right Right Case
    else if (balance < -1 && get_balance((*tree)->right) <= 0)
        *tree = left_rotate(*tree);

    // Right Left Case
    else if (balance < -1 && get_balance((*tree)->right) > 0) {
        (*tree)->right = right_rotate((*tree)->right);
        *tree = left_rotate(*tree);
    }

    return 1;
}

// Search for a value in AVL tree (same as BST)
int AVL_search(AVLTree tree, elem x) {
    if (tree == NULL)
        return 0;

    if (x < tree->data)
        return AVL_search(tree->left, x);
    else if (x > tree->data)
        return AVL_search(tree->right, x);
    else
        return 1;
}

// In-order traversal
void AVL_inorder(AVLTree tree) {
    if (tree != NULL) {
        AVL_inorder(tree->left);
        printf("%d ", tree->data);
        AVL_inorder(tree->right);
    }
}

// Pre-order traversal
void AVL_preorder(AVLTree tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        AVL_preorder(tree->left);
        AVL_preorder(tree->right);
    }
}

// Post-order traversal
void AVL_postorder(AVLTree tree) {
    if (tree != NULL) {
        AVL_postorder(tree->left);
        AVL_postorder(tree->right);
        printf("%d ", tree->data);
    }
}