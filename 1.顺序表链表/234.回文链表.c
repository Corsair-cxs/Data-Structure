/*************************************************************************
	> File Name: 234.回文链表.c
	> Author: 
	> Mail: 
	> Created Time: Friday, December 04, 2020 PM10:05:30 CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool isPalindrome(struct ListNode* head){
    if (!head || !head->next) return true;
    int cnt = 0;
    struct ListNode *p = head, *q;
    while (p) {
        q = p;
        p = p->next;
        cnt++;
    }
    if (q->val != head->val) {
        return false;
    }
    struct ListNode *tail = head, *pre = head->next, *p_head = head->next->next;
    for (int i = 0; i < (((cnt - 1) >> 1)); i++) {
        pre->next = tail;
        tail = pre;
        pre = p_head;
        if (p_head->next) p_head = p_head->next;
    }
    if ((cnt % 2) == 1) tail = tail->next;
    while (tail && tail->next && pre->next) {
        if (tail->val != pre->val) return false;
        //printf("%d %d\n", tail->val, pre->val);
        tail = tail->next;
        pre = pre->next;
    }
    return true;
}

int main() {
    struct ListNode head_node = {1, NULL};
    struct ListNode *head = &head_node, *now = head;
    int n;
    while (~scanf("%d", &n) && n != -1) {
        struct ListNode (*p) = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->val = n;
        now->next = p;
        now = p;
    }
    head = head->next;
    if (isPalindrome(head)) {
        printf("\nOK\n");
    }
    return 0;
}
