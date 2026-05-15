#include "../libdill.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

coroutine void worker(int n) {
    int i = 0, j = 0;
    if (n == 1) {
        for (; i < 10; i++) {
            printf("1: %d\n", i);
            msleep(now() + 100);
        }
        return;
    }
    if (n == 2) {
        for (; j < 10; j++) {
            printf("2: %d\n", j);
            msleep(now() + 100);
        }
        return;
    }
}

int main(int argc, char *argv[]) {
    // each call to go() returns the next free handle and creates a new bundle
    int handle1 = go(worker(1));
    int handle2 = go(worker(2));
    printf("bundle_cnt: %d\n", bundle_cnt());

    // struct dill_bundle_storage st;
    // int handle = dill_bundle_mem(&st);
    //
    // int handle = dill_bundle();
    // printf("handle: %d\n", handle);
    // int b = bundle_go(handle, worker(1));
    // int c = bundle_go(handle, worker(2));
    // printf("a: %d b: %d c: %d\n", handle, b, c);
    // bundle_wait(handle, -1);
    // hclose(handle);
    return 0;
}
