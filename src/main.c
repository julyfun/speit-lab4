#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"

int arr[MAX_LEN];

int main() {
    const int dims[5] = { 10, 100, 1000, 10000, 100000 };
    const int range = 1e6 + 10;
    const int al_cnt = sizeof(FUNC) / sizeof(FUNC[0]);
    const int num_tests = 20;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < al_cnt; j++) {
            rand_num(arr, dims[i], range);
            clock_t st = clock();
            FUNC[j](arr, dims[i]);
            clock_t ed = clock();
            fprintf(
                stderr,
                "\"%s\" costs %lf seconds.\n",
                FUNC_NAMES[j],
                (double)(ed - st) / CLOCKS_PER_SEC
            );
        }
    }
    return 0;
}
