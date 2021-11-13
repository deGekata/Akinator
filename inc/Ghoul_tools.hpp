#ifndef INC_GHOUL_TOOLS
#define INC_GHOUL_TOOLS

#include "stdio.h"
#include "string.h"
#include "ctype.h"

#define MAX_ANS_SIZE 10
#define MAX_ANS_SIZE_STR "10"

enum class Answer {
    STOP,
    DUMP,
    DIFF,
    GUESS,
    UNKNOWN,

};

Answer ask_mode();

bool ask_new_try(bool unknown_answer);

void print_win();

void print_next_try();

void print_lose();

void print_angry();

char* ask_diff_first_p();

char* ask_diff_second_p();

#endif