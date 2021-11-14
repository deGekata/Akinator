#include "stdlib.h"
#include "stdio.h"

int main() {
    char c;

    scanf("%*c", &c);
    printf("read char:\"%c\"", c);
    return 0;
}