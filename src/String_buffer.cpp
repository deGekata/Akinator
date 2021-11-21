#include "../inc/String_buffer.hpp"

void string_buffer_ctor(String_buffer* buff) {
    assert(buff && "buff is NULL");
    
    buff->data = (char**) calloc(STRING_BUFF_BASE_SIZE, sizeof(char*));
    buff->size = 0;
    buff->capacity = STRING_BUFF_BASE_SIZE;
    return;
}

void string_buffer_dtor(String_buffer* buff) {
    assert(buff && "buff is NULL");
    assert(buff->data && "buff data ptr is NULL");

    free(buff->data);

    return;
}

void string_buffer_extend(String_buffer* buff) { 
    assert(buff && "buff is NULL");
    assert(buff->data && "buff data ptr is NULL");

    if (buff->size < buff->capacity) return;

    char** n_ptr = (char**) realloc(buff->data, sizeof(char*) * buff->capacity * STRING_BUFF_EXTEND_SIZE);

    if (n_ptr != NULL) {
        buff->data = n_ptr;
        buff->capacity *= STRING_BUFF_EXTEND_SIZE;
    } else {
        assert(0 && "can`t extend buff data");
    }

}

size_t string_buffer_push(String_buffer* buff, char* n_elem) {
    assert(buff && "buff is NULL");
    assert(n_elem && "new elem ptr is NULL");

    string_buffer_extend(buff);

    buff->data[ buff->size++ ] = n_elem;

    return buff->size - 1;
}

char* string_buffer_find_same(String_buffer* buff, char* elem) {
    assert(buff && "buff is NULL");
    assert(buff->data && "buff data ptr is NULL");

    printf("%s target \n", elem);

    for (size_t it = 0; it < buff->size; ++it) {
        if (strcasecmp(buff->data[it], elem) == 0) {
            return buff->data[it];
        }
        // printf("%s comp \n", buff->data[it]);
    }

    return NULL;
}



