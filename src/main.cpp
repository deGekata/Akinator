#include "../inc/Ghoulinator.hpp"
#include "../inc/Ghoul_tools.hpp"

int main(int argc, char* argv[]) {
    argc = argc;
    argv = argv;
    Ghoulinator ghoul = {0};

    Ghoul_constructor(&ghoul);

    bool unknown_answer = false;

    do {
        switch (ask_mode(unknown_answer)) {
            case Answer::STOP:
                printf("Чел ты... 993 значит...\n");
                break;

            case Answer::DUMP:
                unknown_answer = false;
                printf("Выгружаю базу данных\n");
                break;

            case Answer::DIFF:
                unknown_answer = false;
                printf("Разница... Канеки или Кен?))\n");
                break;

            case Answer::GUESS:
                unknown_answer = false;
                printf("Начинаю угадывать\n");
                break;

            case Answer::UNKNOWN:
                printf("%d unknown ans\n", unknown_answer);
                printf("Неизвестный режим. Попробуйте один из перечисленных.\n");
                unknown_answer = true;
                break;
            default:
                printf("default");
                unknown_answer = true;
                break;
        }

    } while (ask_new_try(unknown_answer));




    Ghoul_destructor(&ghoul);

    return 0;
}