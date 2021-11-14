#ifndef INC_GHOULINATOR
#define INC_GHOULINATOR

#include "assert.h"
#include "../inc/Ghoul_tools.hpp"
#include "../inc/Tree.hpp"

struct Ghoulinator {
    Tree* tree = {0};
    String_buffer* string_buff = {0};
};

void ghoul_constructor(Ghoulinator* ghoul);

void ghoul_destructor(Ghoulinator* ghoul);

void ghoul_load_base(Ghoulinator* ghoul);

void ghoul_dump_base(Ghoulinator* ghoul);

void ghoul_predict(Ghoulinator* ghoul);

void ghoul_get_diff(Ghoulinator* ghoul);

void ghoul_get_definition(Ghoulinator* ghoul);

void ghoul_graph_base(Ghoulinator* ghoul);

#endif