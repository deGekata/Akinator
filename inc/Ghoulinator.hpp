#ifndef INC_GHOULINATOR
#define INC_GHOULINATOR

#include "assert.h"
#include "../inc/Ghoul_tools.hpp"
#include "../inc/Tree.hpp"
#include "../inc/StringFileParser.h"

struct Ghoulinator {
    Tree* tree = {0};
    String_buffer* string_buff = {0};
    char* string_buff_raw = NULL;
};

void ghoul_constructor(Ghoulinator* ghoul);

void ghoul_destructor(Ghoulinator* ghoul);

void ghoul_load_base(Ghoulinator* ghoul, FILE* input);

void ghoul_dump_base(Ghoulinator* ghoul, char* output);

void ghoul_add_object(Ghoulinator* ghoul, Node* prev_node,  Node* ans_node, char* n_object);

void ghoul_predict(Ghoulinator* ghoul);

void ghoul_get_definition(Ghoulinator* ghoul, char* object);

void ghoul_get_difference(Ghoulinator* ghoul, char* object1, char* object2);

void ghoul_graph_base(Ghoulinator* ghoul);

#endif