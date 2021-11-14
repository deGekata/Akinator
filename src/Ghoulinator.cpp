#include "../inc/Ghoulinator.hpp"



void ghoul_constructor(Ghoulinator* ghoul) {
    assert(ghoul && "ghoul ptr is NULL");
 
    ghoul->tree = (Tree*) calloc(1, sizeof(Tree));
    tree_ctor(ghoul->tree);

    ghoul->string_buff = (String_buffer*) calloc(1, sizeof(String_buffer));
    string_buffer_ctor(ghoul->string_buff);

    return;
}

void ghoul_destructor(Ghoulinator* ghoul) {
    assert(ghoul && "ghoul ptr is NULL");

    tree_dtor(ghoul->tree);
    string_buffer_dtor(ghoul->string_buff);

    return;
}

void ghoul_load_base(Ghoulinator* ghoul) {
    
}

void ghoul_dump_base(Ghoulinator* ghoul);

void ghoul_predict(Ghoulinator* ghoul);

void ghoul_get_diff(Ghoulinator* ghoul);

void ghoul_get_definition(Ghoulinator* ghoul);

void ghoul_graph_base(Ghoulinator* ghoul);

