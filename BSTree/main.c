#include <stdio.h>
#include "BST.h"

int main() {
    BSTree tree;
    BST_init(&tree);

    // Insert elements
    BST_insert(&tree, 50);
    BST_insert(&tree, 30);
    BST_insert(&tree, 70);
    BST_insert(&tree, 20);
    BST_insert(&tree, 40);
    BST_insert(&tree, 60);
    BST_insert(&tree, 80);

    // Print traversals
    printf("In-order: ");
    BST_inorder(tree);
    printf("\n");

    printf("Pre-order: ");
    BST_preorder(tree);
    printf("\n");

    printf("Post-order: ");
    BST_postorder(tree);
    printf("\n");

    // Search for an element
    int searchKey = 40;
    if (BST_search(tree, searchKey)) {
        printf("%d found in BST\n", searchKey);
    } else {
        printf("%d not found in BST\n", searchKey);
    }

    // Delete an element
    int deleteKey = 30;
    if (BST_delete(&tree, deleteKey)) {
        printf("%d deleted successfully\n", deleteKey);
    } else {
        printf("%d not found for deletion\n", deleteKey);
    }

    // Print in-order after deletion
    printf("In-order after deletion: ");
    BST_inorder(tree);
    printf("\n");

    return 0;
}