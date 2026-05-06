#include "../libdill.h"
#include <stdio.h>
#include <stdlib.h>
coroutine void worker(const char t) {
    int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = 0,
        k = 0, l = 0, m = 0, n = 0, o = 0, p = 0, q = 0;
    while (1) {
        switch (t) {
        case 'a':
            printf("a: %d\n", a++);
            msleep(now() + 1000);
            break;
        case 'b':
            printf("b: %d\n", b++);
            msleep(now() + 2000);
            break;
        case 'c':
            printf("c: %d\n", c++);
            msleep(now() + 3000);
            break;
        case 'd':
            printf("d: %d\n", d++);
            msleep(now() + 4000);
            break;
        case 'e':
            printf("e: %d\n", e++);
            msleep(now() + 5000);
            break;
        case 'f':
            printf("f: %d\n", f++);
            msleep(now() + 1000);
            break;
        case 'g':
            printf("g: %d\n", g++);
            msleep(now() + 2000);
            break;
        case 'h':
            printf("h: %d\n", h++);
            msleep(now() + 3000);
            break;
        case 'i':
            printf("i: %d\n", i++);
            msleep(now() + 4000);
            break;
        case 'j':
            printf("j: %d\n", j++);
            msleep(now() + 5000);
            break;
        case 'k':
            printf("k: %d\n", k++);
            msleep(now() + 1000);
            break;
        case 'l':
            printf("l: %d\n", l++);
            msleep(now() + 2000);
            break;
        case 'm':
            printf("m: %d\n", m++);
            msleep(now() + 3000);
            break;
        case 'n':
            printf("n: %d\n", n++);
            msleep(now() + 4000);
            break;
        case 'o':
            printf("o: %d\n", o++);
            msleep(now() + 5000);
            break;
        case 'p':
            printf("p: %d\n", p++);
            msleep(now() + 1000);
            break;
        case 'q':
            printf("q: %d\n", q++);
            msleep(now() + 2000);
            break;
        }
    }
}

int main() {
    go(worker('a'));
    go(worker('b'));
    go(worker('c'));
    go(worker('d'));
    go(worker('e'));
    go(worker('f'));
    go(worker('g'));
    go(worker('h'));
    go(worker('i'));
    go(worker('j'));
    go(worker('k'));
    go(worker('l'));
    go(worker('m'));
    go(worker('n'));
    go(worker('o'));
    go(worker('p'));
    go(worker('q'));
    msleep(now() + 50000);
    return 0;
}
