/*************************************************************************
	> File Name: queue.cpp
	> Author: ChenXiansen
	> Mail: 1494089474@qq.com
	> Created Time: Saturday, December 05, 2020 PM08:50:02 CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Queue {
    int *data;
    int head, tail, length;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = 0;
    return q;
}

int front(Queue *q) {
    //if (q == NULL) return -1; 省略
    return q->data[q->head];
}

int empty(Queue *q) {
    return q->head == q->tail; // 头尾重合即是空
}

int push(Queue *q, int val) {
    if (q == NULL) return 0;
    //if (q->tail + 1 == q->length) return 0;
    if ((q->tail + 1) % q->length == q->head) return 0;
    q->data[q->tail] = val;
    q->tail = (q->tail + 1) % q->length;
    return 1;
}

int pop(Queue *q) {
    if (q == NULL) return 0;
    if (empty(q)) return 0;
    q->head = (q->head + 1) % q->length;
    return 1;
}

void output(Queue *q) {
    if (q == NULL) return ;
    if (empty(q)) {
        printf("Queue is empty!\n");
        return ;
    }
    printf("Queue :[");
    for (int i = q->head, j = 0; i != q->tail; i = (i + 1) % q->length, j++) {
        j && printf(", ");
        printf("%d", q->data[i]);
    }
    printf(", ");
    printf("%d", q->data[q->tail]);
    printf("]\n");
    return ;
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
    Queue *q  = init(max_op);
    for (int i = 0; i < 50; i++) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2:{
                printf("Push %d to the queue! ", val);
                printf("Result = %d\n", push(q, val));
            } break;
            case 3: {
                printf("pop %d from the Queue!", front(q));
                printf("result = %d\n", pop(q));
            } break;
        }
        output(q), printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}
