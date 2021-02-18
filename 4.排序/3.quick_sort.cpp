/*************************************************************************
	> File Name: 3.quick_sort.cpp
	> Author: ChenXiansen 
	> Mail: 1494089474@qq.com 
	> Created Time: Sat 21 Nov 2020 04:42:52 PM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b;\
    b = __temp;\
}

#define TEST(arr, n, func, args...) {\
    int *num = (int *)malloc(sizeof(int) * n);\
    memcpy(num, arr, sizeof(int) * n);\
    output(num, n);\
    printf("%s = ", #func);\
    func(args);\
    output(num, n);\
}

void quick_sort0(int *num, int l, int r) {
    if (l > r) return ;
    int x = l, y = r, z = num[x];// z是基准值
    while (x < y) {
        while (x < y && num[y] > z) y--;
        if (x < y) num[x++] = num[y];
        while (x < y && num[x] < z) x++;
        if (x < y) num[y--] = num[x];
    }
    num[x] = z;
    quick_sort0(num, l, x - 1);
    quick_sort0(num, x +1, r);
    return ;
}

void quick_sort1(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sort1(num, x, r);
        r = y;
    }    
    return ;
}

void randint(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
    return ;
}

void output(int *num, int n) {
    printf("\n[ ");
    for (int i = 0; i < n; i++) printf("%d ", num[i]);
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_n 30
    int arr[max_n];
    randint(arr, max_n);
    //quick_sort(arr, 0, max_n - 1);
    TEST(arr, max_n, quick_sort0, num, 0, max_n - 1);
    TEST(arr, max_n, quick_sort1, num, 0, max_n - 1);

    return 0;
}
