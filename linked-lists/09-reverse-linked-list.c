#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

/* LeetCode: Reverse Linked List (#206) - iterative, three pointers */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* next = curr->next;   /* save the rest of the list */
        curr->next = prev;                    /* flip the pointer */
        prev = curr;                          /* move prev forward */
        curr = next;                          /* move curr forward */
    }
    return prev;                              /* prev is the new head */
}

/* ---------- Helpers for local testing ---------- */
struct ListNode* buildList(int* arr, int n) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < n; i++) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = arr[i];
        node->next = NULL;
        if (head == NULL) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

void freeList(struct ListNode* head) {
    while (head) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

/* Reverses the list built from arr and compares with expected */
void runTest(int* arr, int n, int* expected) {
    struct ListNode* head = buildList(arr, n);
    struct ListNode* rev = reverseList(head);

    int pass = 1;
    struct ListNode* p = rev;
    printf("reversed: [");
    for (int i = 0; i < n; i++) {
        if (p == NULL) { pass = 0; break; }
        printf("%d%s", p->val, i < n - 1 ? ", " : "");
        if (p->val != expected[i]) pass = 0;
        p = p->next;
    }
    if (p != NULL) pass = 0;                  /* list longer than expected */
    printf("]  %s\n", pass ? "PASS" : "FAIL");
    freeList(rev);
}

int main(void) {
    int a[] = {1, 2, 3, 4, 5};
    int ea[] = {5, 4, 3, 2, 1};
    runTest(a, 5, ea);          /* typical case */

    int b[] = {1, 2};
    int eb[] = {2, 1};
    runTest(b, 2, eb);          /* edge: two nodes */

    int c[] = {7};
    int ec[] = {7};
    runTest(c, 1, ec);          /* edge: single node */

    /* edge: empty list */
    struct ListNode* empty = reverseList(NULL);
    printf("empty list -> %s  %s\n",
           empty == NULL ? "NULL" : "not NULL",
           empty == NULL ? "PASS" : "FAIL");
    return 0;
}