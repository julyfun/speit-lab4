#include "lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char FUNC_NAMES[][50] = { "void bubble_sort(int arr[], int len)",
                                "void insertion_sort(int arr[], int len)",
                                "void selection_sort(int arr[], int len)",
                                "void merge_sort_api(int arr[], int len)",
                                "void quick_sort_api(int arr[], int len)" };

void (*FUNC[5]
)(int arr[],
  int len) = { bubble_sort, insertion_sort, selection_sort, merge_sort_api, quick_sort_api };

void rand_num(int* arr, int dim, int range) {
    static int init = 0;
    if (!init) {
        srand(time(0));
        init = 1;
    }
    for (int i = 0; i < dim; i++) {
        // 范围为 1 ~ range
        arr[i] = rand() % range + 1;
    }
}

void ivec_print_p1(int* x, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(stderr, "%d ", x[i]);
    }
    fprintf(stderr, "\n");
}

static void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; i++) {
        // 此时到 i - 1 位置已经有序
        int key = arr[i];
        // where to put
        int j = i;
        while (j != 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}

void selection_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int small = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }
        swap(&arr[i], &arr[small]);
    }
}

void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            // 将最大的泡泡放到最后去了
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

static void merge_sort_re(int arr[], int l, int r) {
    static int tmp[MAX_LEN];
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    merge_sort_re(arr, l, mid);
    merge_sort_re(arr, mid + 1, r);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r) {
        if (arr[i] < arr[j]) {
            tmp[pos++] = arr[i++];
        } else {
            tmp[pos++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[pos++] = arr[i++];
    }
    while (j <= r) {
        tmp[pos++] = arr[j++];
    }
    for (int i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
}

void merge_sort_api(int arr[], int len) {
    merge_sort_re(arr, 0, len - 1);
}

static void quick_sort_re(int arr[], int l, int r) {
    if (l >= r) {
        // 注意快排这种递归方式有时候会 l > r
        return;
    }
    int key = arr[(l + r) / 2];
    int i = l, j = r;
    // 结束后 l ~ j 和 i ~ r 是下个要快排的区间，所以 i == j 时候也要继续
    while (i <= j) {
        // 居然不能写 <= 我晕
        // 否则若 3 2, i goes to [2] and does nothing
        // 应该需要是服务于右边可能有的小于 key 的
        while (i <= j && arr[i] < key) {
            i++;
        }
        // i 现在是第一个大于 >= 的数
        while (i <= j && arr[j] > key) {
            j--;
        }
        // j 现在是第一个 <= key 的数
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
        // 交换后，此时 i 左边 (不含 i) 均是小于 key
        // j 右边均是大于 key 捏
    }
    // 循环结束时一定是 j = i - 1，此时 i 左边（不含 i）即 l ~ j 区间小于等于
    quick_sort_re(arr, l, j);
    quick_sort_re(arr, i, r);
}

void quick_sort_api(int arr[], int len) {
    quick_sort_re(arr, 0, len - 1);
}
