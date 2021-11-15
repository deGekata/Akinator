#include "stdlib.h"
#include "stdio.h"

int main() {
    bool choose = true;
    (choose  && ({printf("truthy"); true;})) || (({printf("falsy"); true;}));

    // for(bool br = true; br && (choose || ({printf("falsy"); false;}))  ; br = false) {
    //     printf("truthy");
    // }

    return 0;
}