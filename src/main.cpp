#include "../inc/Ghoulinator.hpp"
#include "../inc/Ghoul_tools.hpp"


int main(int argc, char* argv[]) {
    argc = argc;
    argv = argv;
    Ghoulinator ghoul = {0};

    ghoul_constructor(&ghoul);

    FILE* fl = fopen("/mnt/c/Users/Gekata/Desktop/GitProjects/Ghoulinator/temp.txt", "r");
    printf("%d ptr\n", fl);
    ghoul_load_base(&ghoul, fl);

    bool unknown_answer = false;

    for (bool skip_body = true; skip_body || unknown_answer || ask_yes_no(unknown_answer); skip_body = false) {
        switch (ask_mode(unknown_answer)) {

            case Answer::STOP:
                printf("Чел ты... 993 значит...\n");
                break;

            case Answer::DUMP: {
                    unknown_answer = false;
                    printf("Выгружаю базу данных\n");
                    ghoul_dump_base(&ghoul, "Dump/");
                    ghoul_graph_base(&ghoul);
                }
                break;
            case Answer::DIFF: {
                    char obj1[40] = "";
                    char obj2[40] = "";
                    // fgets(obj1, 40, )
                    //strchr
                    scanf("%40s", obj1);//fgets
                    scanf("%40s", obj2);

                    unknown_answer = false;
                    printf("Разница... Канеки или Кен?))\n");

                    ghoul_get_difference(&ghoul, obj1, obj2);
                }
                break;

            case Answer::GUESS: {
                    unknown_answer = false;
                    ghoul_predict(&ghoul);
                    printf("Начинаю угадывать\n");
                }
                break;
            
            case Answer::DEF: {
                    unknown_answer = false;
                    char object_name[50] = "";
                    printf("Введите имя объекта(максимальная длина 50):\n");
                    scanf("%50s", object_name);
                    printf("Начинаю искать...\n");
                    ghoul_get_definition(&ghoul, object_name);
                }
                break;
            case Answer::UNKNOWN: {
                    printf("%d unknown ans\n", unknown_answer);
                    printf("Неизвестный режим. Попробуйте один из перечисленных.\n");
                    unknown_answer = true;
                }   
                break;

            default:
                printf("default");
                unknown_answer = true;
                break;
        }

    }

    ghoul_destructor(&ghoul);

    return 0;
}





//18 строка с фором - изменённый do while