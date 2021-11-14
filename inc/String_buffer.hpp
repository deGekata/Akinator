#ifndef INC_STRING_BUFFER
#define INC_STRING_BUFFER
#include "stdlib.h"
#include "assert.h"
#include "strings.h"
#include "../inc/MyStack.h"

#define STRING_BUFF_BASE_SIZE 20
#define STRING_BUFF_EXTEND_SIZE 2


struct String_buffer {
    char** data;
    size_t size, capacity;
};

void string_buffer_ctor(String_buffer* buff);

void string_buffer_dtor(String_buffer* buff);

void string_buffer_extend(String_buffer* buff);

void string_buffer_push(String_buffer* buff, char* n_elem);

char* string_buffer_find_same(String_buffer* buff, char* elem);

#endif