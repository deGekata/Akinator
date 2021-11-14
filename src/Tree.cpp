#include "../inc/Tree.hpp"

void tree_ctor(Tree* tree) {
    assert(tree && "tree ptr is NULL");



    return;
}

void tree_dtor(Tree* tree) {
    assert(tree && "tree ptr is NULL");

    if (tree->root != NULL) {
        node_dtor(tree->root);
    }

    return;
}


Node* tree_find_obj(Node* node, SafeStack* stack, char* target_object) {
    assert(node && "node ptr is NULL");
    assert(stack && "stack ptr is NULL");

    pushStack(stack, (int*)node);

    if (strcasecmp(node->data, target_object) == 0) {
        return node;
    }

    if (node->left != NULL && tree_find_obj(node->left, stack, target_object)) return (Node*)stack->arr[stack->size - 1];
    
    if (node->right != NULL && tree_find_obj(node->right, stack, target_object)) return (Node*)stack->arr[stack->size - 1];

    pop(stack);

    return NULL;

}

Node* node_ctor() {
    Node* ret_val = (Node*) calloc(1, sizeof(Node));

    return ret_val;
}

void node_dtor(Node* node) {
    assert(node && "node ptr is NULL");

    if (node->left != NULL) node_dtor(node->left);

    if (node->right != NULL) node_dtor(node->right);

    node->left = node->right = NULL;

    node->data = NULL;

    free(node);

    return;
}