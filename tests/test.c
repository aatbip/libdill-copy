#include "../libdill.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int port;
    if (argc > 1) {
        port = atoi(argv[1]);
    }
    printf("PORT %d\n", port);
    struct ipaddr addr;
    int rc = ipaddr_local(&addr, NULL, port, 0);
    if (rc < 0) {
        perror("Can't open listening socket");
        exit(EXIT_FAILURE);
    }
    int ls = tcp_listen(&addr, 10);
    assert(ls >= 0);
    while (1) {
        int s = tcp_accept(ls, NULL, -1);
        assert(s >= 0);
        printf("New connection!\n");
        rc = hclose(s);
        assert(rc == 0);
    }

    exit(EXIT_SUCCESS);
}
