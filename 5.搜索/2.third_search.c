/*************************************************************************
	> File Name: 2.third_search.cpp
	> Author: ChenXiansen 
	> Mail: 1494089474@qq.com 
	> Created Time: Sun 22 Nov 2020 02:30:21 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef double T;
#define T_token "%lf"
#define epsl 1e-10

#define P(val) {\
    printf("%s: "T_token"\n", #val, val);\
}
#define P_ans(ans, temp, x, n) {\
    printf("ans += "T_token" + "T_token" * ("T_token" ^ %d)\n", ans, temp, x, n);\
}
#define P_func(n, argv) {\
    __typeof(n) __temp = n;\
    printf("Func(x) = ");\
    while (--n > -1) {\
        printf("[ "T_token" * (x ^ %d) ]", argv[n], n);\
        n && printf(" + ");\
    }\
    printf("\n");\
    n = __temp;\
}
/*
 * n阶函数表达式 - 变参函数形式
 */
T fact_func(T x, int n, ...) {
    T ans = 0;
    va_list arg;
    va_start(arg, n);
    while (n--) {
        T temp = va_arg(arg, T);
        P_ans(ans, temp, x, n);
        ans += pow(x, n) * temp;
        P(ans);
    }
    return ans;
}
/*
 * n阶函数表达式 - 数组传参形式
 */
T fact_func2(T x, int n, T* argv) {
    T ans = 0;
    while(--n > -1) {
        T temp = argv[n];
        ans += pow(x, n) * temp;
    }
    return ans;
}

T thrid_search(T head, T tail, int flag, T(*func)(T, int, T*), int n, T* argv) {
    if (abs(tail - head) < epsl) return head;
    T m1, m2, l = head, r = tail;
    if (flag > 0) {
        while (l + epsl < r) {
            m1 = ((r - l) / 3) + l;
            m2 = ((r - l) / 3 * 2) + l;
            if (func(m1, n, argv) <= func(m2, n, argv)) {
                r = m2;
            } else {
                l = m1;
            }
        }
        return l;
    } else {
        while (l + epsl < r) {
            m1 = ((r - l) / 3) + l;
            m2 = ((r - l) / 3 * 2) + l;
            if (func(m1, n, argv) <= func(m2, n, argv)) {
                l = m1;
            } else {
                r = m2;
            }
        }
        return l;
    }
}

int main() {
    int n, flag;
    /*
    printf("请输入函数最高元数: ");
    scanf ("%d", &n);
    n++;*/
    n = 3;
    printf("请输入一元二次函数参数: ");
    T* hz_argv = (T*)malloc(sizeof(T) * 3);
    for (int i = n - 1; i >= 0; i--) {
        scanf(T_token, &hz_argv[i]);
    }
    P_func(n, hz_argv);
    flag = (hz_argv[n - 1] > 0) ? 1 : -1;
    printf("查找函数极值点：");
    printf(T_token"\n", thrid_search(-100000, 100000, flag, fact_func2, n, hz_argv));
    free(hz_argv);
    return 0;
}
