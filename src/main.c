#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"

int arr[MAX_LEN];
int min(int x, int y) {
    return x < y ? x : y;
}

int main() {
    const int dims[5] = { 10, 100, 1000, 10000, 100000 };
    const int num_dims = 5;
    const int range = 1e6 + 10;
    const int al_cnt = sizeof(FUNC) / sizeof(FUNC[0]);
    const int num_tests = 3;
    // int first_test[al_cnt];
    // memset(first_test, 0, sizeof first_test);
    freopen("res.csv", "w", stdout);
    for (int i = 0; i < al_cnt; i++) {
        fprintf(stderr, "--- %s:\n", FUNC_NAMES[i]);
        int sampled = 0;
        for (int j = 0; j < num_dims; j++) {
            double ave_time = 0.0;
            const int len = dims[j];
            for (int k = 0; k < num_tests; k++) {
                rand_num(arr, len, range);
                if (!sampled) {
                    fprintf(stderr, "Sample data:\n");
                    ivec_print_p1(arr, len);
                }
                clock_t st = clock();
                FUNC[i](arr, len);
                clock_t ed = clock();
                if (!sampled) {
                    fprintf(stderr, "Sample sort:\n");
                    ivec_print_p1(arr, len);
                    fprintf(stderr, "[  size] time\n");
                }
                // ivec_print_p1(arr, dims[j]);
                ave_time += ed - st;
                sampled = 1;
            }
            ave_time = ave_time / num_tests / CLOCKS_PER_SEC;
            fprintf(stderr, "[%6d] %lfs\n", len, ave_time);
            fprintf(stdout, "%lf", ave_time);
            if (j != num_dims - 1) {
                fprintf(stdout, ",");
            }
        }
        fprintf(stdout, "\n");
    }
    return 0;
}
