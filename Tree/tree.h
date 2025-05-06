typedef int elem;

typedef struct tNode {
    elem data;
    struct tNode* right;
    struct tNode* left;
} tNode;

typedef tNode* tPTR;

void TR_init(tPTR* t);
int TR_empty(tPTR root);
elem TR_data(tPTR node);

int TR_insert_root(tPTR* root, elem x);
int TR_insert_left(tPTR node, elem x);
int TR_insert_right(tPTR node, elem x);
int TR_delete_root(tPTR* root, elem* x);
int TR_delete_left(tPTR parent, elem* x);
int TR_delete_right(tPTR parent, elem* x);