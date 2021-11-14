#include "../inc/Ghoul_tools.hpp"



Answer ask_mode(bool unknown_answer) {
    char answer[MAX_ANS_SIZE];
    if (!unknown_answer) {
        printf("Какой режим хотите выбрать?\n"
            "Доступные режимы:\n"
            "\tGuess\n"
            "\tStop\n"
            "\tDiff\n"
            "\tDump\n"
        );
    }

    scanf("%" MAX_ANS_SIZE_STR "s", answer);

    size_t str_len = strlen(answer);
    for (size_t chr_pos = 0; chr_pos < str_len; ++chr_pos) {
        answer[chr_pos] =  (char) tolower(answer[chr_pos]);
    }

    if(strcmp(answer, "stop") == 0) {
        return Answer::STOP;
    }
    
    if(strcmp(answer, "dump") == 0) {
        return Answer::DUMP;
    }
    
    if(strcmp(answer, "diff") == 0) {
        return Answer::DIFF;
    }

    if(strcmp(answer, "guess") == 0) {
        return Answer::GUESS;
    } 

    return Answer::UNKNOWN;
}

bool ask_new_try(bool unknown_answer) {
    char answer[MAX_ANS_SIZE];
    bool not_correct_answer = true;
    bool ret_val = false;

    if (!unknown_answer) {
        printf("Хотите попробовать ещё раз?\n");
    }

    if (unknown_answer) {
        printf("wtf");
        return 1;
    }

    while (not_correct_answer) {
        scanf("%" MAX_ANS_SIZE_STR "s", answer);

        size_t str_len = strlen(answer);
        for (size_t chr_pos = 0; chr_pos < str_len; ++chr_pos) {
            answer[chr_pos] =  (char) tolower(answer[chr_pos]);
        }   

        if (strcmp(answer, "yes") == 0) {
            not_correct_answer = false;
            ret_val = 1;
        } else if (strcmp(answer, "no") == 0) {
            not_correct_answer = false;
            ret_val = 0;
        } else {
            printf("Неизвестный ответ\n");
        }

    }

    return ret_val;
}

char* ask_diff_first_p() {
    printf("Назови 1 объект:\n");
    char* str;
    scanf("%ms", &str);
    return str;
}

char* ask_diff_second_p() {
    printf("Назови 2 объект:\n");
    char* str;
    scanf("%ms", &str);
    return str;
}

void print_win() {
    printf("Я победил, ха. Я самый умный у меня неуд(10)\n");
}

void print_next_try() {
    printf("Ладно, попробуем ещё раз\n");
}

void print_lose() {
    printf("Хорошо, я сдаюсь. Ты победил.\n");
}

void print_angry() {
    printf("Как я погляжу ты сам не знаешь кого загадал. Так что будем считать я победил.\n");  
}

