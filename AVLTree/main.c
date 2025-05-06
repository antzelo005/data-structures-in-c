#include <stdio.h>
#include "AVL.h"

void inorder(AVLTree root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", AVL_data(root));
    inorder(root->right);
}

int main() {
    AVLTree tree;
    AVL_init(&tree);

    int values[] = {30, 20, 40, 10, 25, 35, 50, 5};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        AVL_insert(&tree, values[i]);
    }

    printf("Inorder traversal of the AVL tree: ");
    inorder(tree);
    printf("\n");

    return 0;
}
