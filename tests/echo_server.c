/*Asynchronous echo server*/
#include "../libdill.h"
#include <stdio.h>

void counter() {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", i);
        msleep(now() + 1000);
    }
}

int main(void) {
    char msg[1024];
    struct ipaddr addr;
    ipaddr_local(&addr, NULL, 5555, 0);
    int ls = tcp_listen(&addr, 10);
    while (1) {
        int s = tcp_accept(ls, NULL, -1);
        printf("new connection\n");
        go(counter());
    }
}
