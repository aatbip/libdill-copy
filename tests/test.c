#include "../libdill.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int port;
    if (argc > 1) {
        port = atoi(argv[1]);
    }
    printf("%d\n", port);
    exit(EXIT_SUCCESS);
}
