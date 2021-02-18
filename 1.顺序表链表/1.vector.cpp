/*************************************************************************
	> File Name: 1.vector.cpp
	> Author: ChenXiansen 
	> Mail: 1494089474@qq.com 
	> Created Time: Thu 12 Nov 2020 03:28:16 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

<<<<<<< HEAD
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

=======
>>>>>>> ade5ffbda87feebf47c30238c0784b0f507c4cd4
typedef struct Vector {
    int *data;
    int size, length;
} Vec;

Vec *init(int n) {
    Vec * v = (Vec*) malloc (sizeof(Vec));
    v->data = (int *)malloc(sizeof(int) *n);
    v->size = n;
    v->length = 0;
    return v;
}

void clear(Vec *v) {
    if (v == NULL) return ;
    free(v->data);
    free(v);
    return ;
}

<<<<<<< HEAD
int expand (Vec *v) {
    int extr_size = v->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(v->data, sizeof(int) * (v->size + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (extr_size == 0) return 0;
    v->data = p;
    v->size = v->size + extr_size;
    return 1;
}

int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) {
        int temp = v->size;
        if (expand(v)) printf(GREEN("expand vector size from %d to %d\n"), temp, v->size);
    }
=======
int insert(Vec *v, int val, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind > v->length) return 0;
    if (v->length == v->size) return 0;
>>>>>>> ade5ffbda87feebf47c30238c0784b0f507c4cd4
    for(int i = v->length; i > ind; i--) {
        v->data[i] = v->data[i - 1];
    }
    v->data[ind] = val;
    v->length += 1;
    return 1;
}

int erase(Vec *v, int ind) {
    if (v == NULL) return 0;
    if (ind < 0 || ind >= v->length) return 0;
    for (int i = ind + 1; i < v->length; i++) {
        v->data[i - 1] = v->data[i];
    }
    v->length -= 1;
    return 1;
}

<<<<<<< HEAD
=======
int expand (Vec *v) {

}

>>>>>>> ade5ffbda87feebf47c30238c0784b0f507c4cd4
void output(Vec *v) {
    if (v == NULL) return ;
    printf("Vector : [");
    for (int i = 0; i < v->length; i++) {
        i && printf(", ");
        printf("%d", v->data[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
<<<<<<< HEAD
    #define max_op 200
    Vec *v = init(2);
=======
    #define max_op 20
    Vec *v = init(max_op);
>>>>>>> ade5ffbda87feebf47c30238c0784b0f507c4cd4
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (v->length + 3) - 1;
        int op = rand() % 4;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("Insert %-3d at %-3d to Vector = %d \n", val, ind, insert(v, val, ind));
            } break;
            case 3: {
                printf("Erase a item at %-3d from Vector = %-3d \n", ind, erase(v, ind));
            } break;
        }
        output(v);
        printf("\n");
    }

    return 0;
}
