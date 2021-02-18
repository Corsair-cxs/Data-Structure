/*************************************************************************
	> File Name: 1.binary_search.cpp
	> Author: ChenXiansen 
	> Mail: 1494089474@qq.com 
	> Created Time: Sat 21 Nov 2020 07:12:28 PM CST
 ************************************************************************/
#include <stdio.h>

#define P(func) {\
    printf("%s = %d\n", #func, func);\
}

// 1 3 5 7 9 11
int binary_search1(int *num, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head +tail) >> 1;
        if (num[mid] == x) return mid;
        if (num[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

// 11111110000000
int binary_search2(int *num, int n) {
    int head = -1, tail = n - 1, mid;
    while (head < tail) {
        mid = (head + tail + 1) >> 1;
        if (num[mid] == 1) head = mid;
        else tail = mid - 1;
    }
    return head;
}

// 00000001111111
int binary_search3(int *num, int n) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (num[mid] == 0) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int arr1[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int arr2[10] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int arr3[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    int arr4[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    P(binary_search1(arr1, 10, 7));
    P(binary_search2(arr2, 10));
    P(binary_search2(arr4, 10));
    P(binary_search3(arr3, 10));
    P(binary_search3(arr4, 10));
    return 0;
}
