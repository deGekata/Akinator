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

void print_tree(Tree* tree, FILE* output) {
    assert(tree && "tree ptr is null");
    assert(output && "output file ptr is null");

    int offset = 0;
    print_node(tree->root, output, &offset);
    return;
}

bool find_leaf_tree(Tree* tree, SafeStack* stack, char* object) {
    assert(tree   && "tree ptr is null");
    assert(object && "search target ptr is null");
    assert(stack  && "stack ptr is null");

    find_node(tree->root, stack, object, 1);

    if (stack->size == 0)
        return false;
    
    return true;
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

bool find_node(Node* node, SafeStack* stack, char* object, bool way) {
    if (node->left != NULL) {
        pushStack(stack, (my_type)way);
        pushStack(stack, (my_type)node);
        
        if (find_node(node->left, stack, object, 0)) {
            return true;
        } else if (find_node(node->right, stack, object, 1)) {
            return true;
        }
        

        pop(stack);
        pop(stack);
        return false;
    } else {
        if (strcasecmp(node->data, object) == 0) {
            pushStack(stack, (my_type)way);            
            pushStack(stack, (my_type)object);
            return true;
        }
    }

    return false;
}

void print_node(Node* node, FILE* output, int* offset) {
    
    if (node == NULL) {
        return;
    }
    
    print_spacer(output, *offset);
    fprintf(output,"%s\n", node->data);

    ++(*offset);

    if (node->left) {
        print_spacer(output, *offset);
        fprintf(output, "{\n");

        ++(*offset);
        print_node(node->left, output, offset);
        --(*offset);

        print_spacer(output, *offset);
        fprintf(output, "}\n");
    }
    
    if (node->right) {
        print_spacer(output, *offset);
        fprintf(output, "{\n");

        ++(*offset);
        print_node(node->right, output, offset);
        --(*offset);
        
        print_spacer(output, *offset);
        fprintf(output, "}\n");
    }
    (*offset)--;
    return;
}


void print_spacer(FILE* output, int offset) {
    for (int it = 0; it < offset; ++it) {
            fprintf(output, "    ");
    }
}