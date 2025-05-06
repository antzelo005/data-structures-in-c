#include <stdio.h>
#include "tree.h"

int main() {
    tPTR root;
    TR_init(&root);

    // Insert root
    TR_insert_root(&root, 10);
    printf("Root data: %d\n", TR_data(root)); // Should print 10

    // Insert left and right children
    TR_insert_left(root, 5);
    TR_insert_right(root, 15);
    printf("Left child data: %d\n", TR_data(root->left)); // Should print 5
    printf("Right child data: %d\n", TR_data(root->right)); // Should print 15

    // Delete left child
    elem deletedValue;
    if (TR_delete_left(root, &deletedValue)) {
        printf("Deleted left child with value: %d\n", deletedValue); // Should print 5
    }

    // Delete root
    if (TR_delete_root(&root, &deletedValue)) {
        printf("Deleted root with value: %d\n", deletedValue); // Should print 10
    }

    return 0;
}