#ifndef INC_TREE
#define INC_TREE

#include "stdio.h"
#include "../inc/String_buffer.hpp"
#include "../inc/MyStack.h"


struct Node {
    Node* left;
    Node* right;
    char* data;
};

struct Tree {
    Node* root = NULL;
};

void tree_ctor(Tree* tree);

void tree_dtor(Tree* tree);

bool find_leaf_tree(Tree* tree, SafeStack* stack, char* object);

void print_tree(Tree* tree, FILE* output);

Node* node_ctor();

void node_dtor(Node* node);

bool find_node(Node* node, SafeStack* stack, char* object, bool is_print);

void print_node(Node* node, FILE* output, int* offset);

void print_spacer(FILE* output, int offset);

#endif 