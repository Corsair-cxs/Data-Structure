/*************************************************************************
	> File Name: 3.queue.cpp
	> Author: ChenXiansen 
	> Mail: 1494089474@qq.com 
	> Created Time: Thu 12 Nov 2020 08:20:13 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[m"
#define GREEN(a) COLOR(a, 33)
#define YELLOW(a) COLOR(a, 33)
#define BLUE(a) COLOR(a, 33)
#define RED(a) COLOR(a, 33)
#define WHITE(a) COLOR(a, 33)
typedef struct Queue {
    int *data;
    int head, tail, length, count;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = q->count = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail;
}

int push(Queue *q, int val) {
    if (!q) return 0;
    if (q->count == q->length) return 0;
    q->data[(q->tail++) % q->length] = val;
    q->count++;
    return 1;
}

int pop(Queue *q) {
    if (!q) return 0;
    if (!q->count) return 0;
    q->head = (q->head + 1) % q->length;
    q->count--;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return;
    printf(RED("Lenth of Queue: "));
    printf("%d\n", q->count);
    printf("Queue : [");
    int k = q->head;
    for (int i = 0; i < q->count; i++) {
        printf("%d", q->data[k]);
        k = (k + 1) % q->length;
        (i != q->count - 1) && printf(", ");
    }
    printf(" ]\n");
}

void clear(Queue *q) {
    if (q == NULL) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(max_op);
    for (int i = 0; i < max_op * 2; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("Push %d to the Queue! ", val);
                printf("Result = %d\n", push(q, val));
            } break;
            case 3: {
                printf("Pop %d from the Queue! ", front(q));
                printf("Result = %d\n", pop(q));
            } break;
        }
        output(q);
        printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}
