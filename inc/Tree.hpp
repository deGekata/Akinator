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

Node* tree_find_obj(Node* node, SafeStack* stack, char* target_object);

Node* node_ctor();

void node_dtor(Node* node);

#endif 