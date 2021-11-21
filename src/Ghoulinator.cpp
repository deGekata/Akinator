#include "../inc/Ghoulinator.hpp"

const size_t Max_cmd_len  = 300;
const size_t Max_out_file_len = 300;

const char* Img_dump_dir = "./mnt/c/Users/Gekata/Desktop/GitProjects/Ghoulinator/Dump/";

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

    if (ghoul->string_buff_raw) {
        free(ghoul->string_buff_raw);
    }

    return;
}


void ghoul_load_base(Ghoulinator* ghoul, FILE* input) {
    assert(ghoul && "ghoul is null ptr");
    assert(input && "input is null ptr");

    if (ghoul->tree->root != NULL) {
        node_dtor(ghoul->tree->root);
    }

    Text text = {0};
    fillText(&text, input);
    ghoul->string_buff_raw = text.raw_line;

    for (size_t it = 0; it < text.lines_cnt; ++it) {
        size_t n_offset = 0;
        skip_spaces(text.strings[it].begin, &n_offset);
        text.strings[it].begin += n_offset;
    }
   
    ghoul->tree->root = node_ctor();
    Node* cur_node = ghoul->tree->root;

    SafeStack stack = {0};
    createStack(&stack);

    for (size_t it = 0; it < text.lines_cnt - 1; ++it) {
        char* cur_char = text.strings[it].begin;

        switch (*cur_char) {

        case '\'':
            cur_node->data = text.strings[it].begin;
            string_buffer_push(ghoul->string_buff, cur_node->data);
            break;
        
        case '{':
            pushStack(&stack, (my_type)cur_node);

            if (!(cur_node->left)) {
                cur_node->left = node_ctor();
                cur_node = cur_node->left;

            } else {
                if (cur_node->right) {
                    assert(0 && "invalid db format");
                }

                cur_node->right = node_ctor();
                cur_node = cur_node->right;
            }
            
            break;

        case '}':
            if (stack.size == 0 && (it + 1) < text.lines_cnt) {
                assert(0 && "invalid db format, not enough lines");
            }
            if ((cur_node->left != NULL && cur_node->right == NULL) || (cur_node->left == NULL && cur_node->right != NULL)) {
                assert(0 && "invalid db format, vertex cant have only one child");
            }

            cur_node = (Node*) pop(&stack);
            break;

        case '(':

            if (cur_node->left != NULL || cur_node->right != NULL) {
                assert(0 && "invalid db format, node already have child and cant store ");
            }

            cur_node->data = text.strings[it].begin;
            string_buffer_push(ghoul->string_buff, cur_node->data);
            
            break;

        default:
            assert(0 && "symbol error");    
            break;

        }

    }

    free(text.strings);
}

void ghoul_dump_base(Ghoulinator* ghoul, char* output_file_dir) {
    assert(ghoul && "ghoul is null");
    assert(output_file_dir && "output file ptr is null");
    assert(ghoul->tree && "Aogiri tree is null");

    static int dump_counter = 0;
    char buff[200];
    sprintf(buff, "%s/ghoul_dump_%d.txt\0", output_file_dir, dump_counter);
    output_file_dir = output_file_dir;
    FILE* output = stdout;//fopen(buff, "a+");

    print_tree(ghoul->tree, output);

    ++dump_counter;
    return;
}

void ghoul_add_object(Ghoulinator* ghoul, Node* prev_node,  Node* ans_node, char* n_object) {
    assert(ghoul && "ghoul is null");
    assert(ghoul->tree && "Aogiri member is null");
    assert(n_object && "n_object is null");

    string_buffer_push(ghoul->string_buff, n_object);

    char* question_buff = (char*) calloc(40, sizeof(char));

    printf("В чём отличие?(не более 40 символов)");
    scanf("%40s", question_buff);

    if (ans_node = prev_node->left) {
        prev_node->left = node_ctor();
        prev_node->left->data = question_buff;
        prev_node->left->left = ans_node;
        prev_node->left->right = node_ctor();
        prev_node->left->right->data = n_object;
    } else {
        prev_node->right = node_ctor();
        prev_node->right->data = question_buff;
        prev_node->right->left = ans_node;
        prev_node->right->right = node_ctor();
        prev_node->right->right->data = n_object;
    }

}

void ghoul_predict(Ghoulinator* ghoul) {
    assert(ghoul && "ghoul is null");
    assert(ghoul->tree && "Aogiri tree is null");
    assert(ghoul->tree->root && "Aogiri root is null");

    Node* prev_node = NULL;
    Node* cur_node = ghoul->tree->root;
    
    for(;cur_node->left != NULL;) { //while
        printf("%s???\n", cur_node->data);

        bool answer =  ask_yes_no(true);//cancer if
        
        /*if*/ (answer && ({
            prev_node = cur_node; 
            cur_node = cur_node->left;
        1;})) || /*else*/ ({
            prev_node = cur_node; 
            cur_node = cur_node->right;
        });
    }

    printf("Это он %s ?????????????????\n", cur_node->data);

    bool answer =  ask_yes_no(true);
    if (answer) {
        print_win();
    } else {
        print_lose();
        char* n_object;
        scanf("%ms", &n_object);
        ghoul_add_object(ghoul, prev_node, cur_node, n_object);
    }

}

void ghoul_get_difference(Ghoulinator* ghoul, char* object1, char* object2) {
    assert(ghoul && "ghoul is null");
    assert(object1 && "output file ptr is null");
    assert(object2 && "output file ptr is null");
    assert(ghoul->tree && "Aogiri tree is null");

    char* search_result1 =  string_buffer_find_same(ghoul->string_buff, object1);
    char* search_result2 =  string_buffer_find_same(ghoul->string_buff, object2);

    if (search_result1 == NULL) {
        print_unknown_object();
        return;
    }

    if (search_result2 == NULL) {
        print_unknown_object();
        return;
    }

    SafeStack stack1;
    createStack(&stack1);
    SafeStack stack2;
    createStack(&stack2);

    find_leaf_tree(ghoul->tree, &stack1, object1);
    find_leaf_tree(ghoul->tree, &stack2, object2);
    
    int it1 = 1, it2 = 1;
    
    for (; it1 < stack1.size - 1 && it2 < stack2.size - 1; it1 += 2, it2 += 2) {

        if ((bool)stack1.arr[it1 + 1] == (bool)stack2.arr[it2 + 1]) {
            printf("Одинаково: %s\n", ((Node*)stack1.arr[it1])->data);//сделать позера
        }  else {
            break;
        }

    }

    for (; it1 < stack1.size - 1; it1 += 2) {
        if (!(bool)stack1.arr[it1 + 1])
            printf("Отличие 1 чела:%s\n", ((Node*)stack1.arr[it1])->data);
        else 
            printf("Отличие 1 чела: не %s\n", ((Node*)stack1.arr[it1])->data);
    }

    for (; it2 < stack2.size - 1; it2 += 2) {
        if (!(bool)stack2.arr[it2 + 1])
            printf("Отличие 2 чела:%s\n", ((Node*)stack2.arr[it2])->data);
        else 
            printf("Отличие 2 чела: не %s\n", ((Node*)stack2.arr[it2])->data);
    }
    
    return;
}

void ghoul_get_definition(Ghoulinator* ghoul, char* object) {
    assert(ghoul && "ghoul is null");
    assert(object && "output file ptr is null");
    assert(ghoul->tree && "Aogiri tree is null");

    char* search_result =  string_buffer_find_same(ghoul->string_buff, object);

    if (search_result == NULL) {
        print_unknown_object();
        return;
    }

    SafeStack stack;
    createStack(&stack);

    bool tree_search_result = find_leaf_tree(ghoul->tree, &stack, object);
    
    for (int it = 1; it < stack.size; it += 2) {
        if(!(bool)stack.arr[it + 1]) {
            printf("%s\n", ((Node*)stack.arr[it])->data);
        } else {
            printf("Не %s\n", ((Node*)stack.arr[it])->data);
        }
    }
    
    return;
}

void ghoul_graph_base(Ghoulinator* ghoul) {
    assert(ghoul && "ghoul is null");
    assert(ghoul->tree && "Aogiri tree is null");

    static int dump_number = 0;

    char filename[Max_out_file_len] = {};
    sprintf(filename, "/mnt/c/Users/Gekata/Desktop/GitProjects/Ghoulinator/Dump/LIST_DMP_№%d.dot", dump_number);

    FILE* file = fopen(filename, "w");
    assert(file && "cant open file");

    printf("%p file ptr\n", file);
    fprintf(file,   "digraph G{"
                    "   ");

    SafeStack stack;
    createStack(&stack);
    pushStack(&stack, (my_type)ghoul->tree);

    Node* cur_node = NULL;
    while (stack.size > 0) {
        printf("lol\n");
        cur_node = (Node*) pop(&stack);
        fprintf(file, "N%p[label=\"%s\"];\n", cur_node, cur_node->data);

        if (cur_node->left != NULL) {
            fprintf(file, "N%p->N%p[label=\"+\"];\n", cur_node, cur_node->left);
            pushStack(&stack, (my_type)cur_node->left);
        }

        if (cur_node->right != NULL) {
            fprintf(file, "N%p->N%p[label=\"-\"];\n", cur_node, cur_node->right);
            pushStack(&stack, (my_type)cur_node->right);
        }
         
    }
    
    fprintf(file, "}");
    fclose(file);

    char command[Max_cmd_len] = {};
    sprintf(command, "dot /mnt/c/Users/Gekata/Desktop/GitProjects/Ghoulinator/Dump/LIST_DMP_№%d.dot -T png -o /mnt/c/Users/Gekata/Desktop/GitProjects/Ghoulinator/Dump/LIST_DMP_№%d.png", dump_number, dump_number);
    system(command);

    ++dump_number;
}

