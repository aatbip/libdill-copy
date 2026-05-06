#include "../libdill.h"
#include <stdio.h>
#include <stdlib.h>
coroutine void worker(const char t) {
    int i = 0, j = 0;
    while (1) {
        if (t == 'a') {
            printf("a: %d\n", i++);
        } else {
            printf("b: %d\n", j++);
        }
        msleep(now() + random() % 500);
    }
}

int main() {
    go(worker('a'));
    go(worker('b'));
    msleep(now() + 5000);
    return 0;
}
