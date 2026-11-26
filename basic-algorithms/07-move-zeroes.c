#include <stdio.h>

/* LeetCode: Move Zeroes (#283) - two pointers, in place */
void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;   /* next slot for a non-zero value */

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int temp = nums[insertPos];
            nums[insertPos] = nums[i];
            nums[i] = temp;
            insertPos++;
        }
    }
}

/* ---------- Local tests ---------- */
void runTest(int* nums, int n, int* expected) {
    moveZeroes(nums, n);
    int pass = 1;
    printf("result: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", nums[i], i < n - 1 ? ", " : "");
        if (nums[i] != expected[i]) pass = 0;
    }
    printf("]  %s\n", pass ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {0, 1, 0, 3, 12};
    int ea[] = {1, 3, 12, 0, 0};
    runTest(a, 5, ea);       /* typical case */

    int b[] = {0};
    int eb[] = {0};
    runTest(b, 1, eb);       /* edge: single zero */

    int c[] = {1, 2, 3};
    int ec[] = {1, 2, 3};
    runTest(c, 3, ec);       /* edge: no zeroes */

    int d[] = {0, 0, 1};
    int ed[] = {1, 0, 0};
    runTest(d, 3, ed);       /* edge: zeroes at the start */
    return 0;
}