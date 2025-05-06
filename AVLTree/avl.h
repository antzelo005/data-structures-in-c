#ifndef AVL_H
#define AVL_H

typedef int elem;

typedef struct AVLNode {
    elem data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height; // Height of the node
} AVLNode;

typedef AVLNode* AVLTree;

// Initialization
void AVL_init(AVLTree* tree);

// Check if tree is empty
int AVL_empty(AVLTree tree);

// Get data from node
elem AVL_data(AVLTree node);

// Basic operations
int AVL_insert(AVLTree* tree, elem x);
int AVL_delete(AVLTree* tree, elem x);
int AVL_search(AVLTree tree, elem x);

// Traversals
void AVL_inorder(AVLTree tree);
void AVL_preorder(AVLTree tree);
void AVL_postorder(AVLTree tree);

#endif // AVL_H