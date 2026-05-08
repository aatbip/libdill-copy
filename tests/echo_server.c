/*Asynchronous echo server*/
#include "../libdill.h"
#include <stdio.h>
#include <unistd.h>

coroutine void routine(int s) {
    int framed = suffix_attach(s, "\n", 1);
    if (framed < 0) {
        perror("suffix_attach");
        hclose(s);
        return;
    }

    while (1) {
        char msg[100];
        ssize_t rc = mrecv(framed, msg, sizeof(msg) - 1, -1);
        if (rc < 0) {
            perror("mrecv");
            break;
        }
        msg[rc] = '\0';
        msend(framed, msg, sizeof(msg) - 1, -1);
        printf("msg: %s\n", msg);
    }

    s = suffix_detach(framed, -1);
    hclose(s);
}

int main(void) {
    char msg[1024];
    struct ipaddr addr;
    ipaddr_local(&addr, NULL, 5555, 0);
    int ls = tcp_listen(&addr, 10);
    while (1) {
        int s = tcp_accept(ls, NULL, -1);
        printf("new connection\n");
        go(routine(s));
    }
    msleep(-1);
}
