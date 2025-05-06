#ifndef BST_H
#define BST_H

typedef int elem; // BST elements are integers

typedef struct BSTNode {
    elem data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

typedef BSTNode* BSTree;

// Initializes the BST
void BST_init(BSTree* tree);

// Checks if the BST is empty
int BST_empty(BSTree tree);

// Returns the data of a node
elem BST_data(BSTree node);

// Inserts a new element into the BST
int BST_insert(BSTree* tree, elem x);

// Deletes an element from the BST
int BST_delete(BSTree* tree, elem x);

// Searches for an element in the BST
int BST_search(BSTree tree, elem x);

// Traversals (for printing)
void BST_inorder(BSTree tree);
void BST_preorder(BSTree tree);
void BST_postorder(BSTree tree);

#endif // BST_H