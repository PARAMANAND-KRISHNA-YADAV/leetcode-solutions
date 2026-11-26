#include <stdio.h>
#include <stdlib.h>

/* LeetCode: Two Sum - brute force */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return result;
}

/* ---------- Local tests ---------- */
void runTest(int* nums, int n, int target, int e0, int e1) {
    int size;
    int* r = twoSum(nums, n, target, &size);
    int pass = (size == 2 && r[0] == e0 && r[1] == e1);
    printf("target=%d -> [%d, %d]  expected [%d, %d]  %s\n",
           target, r[0], r[1], e0, e1, pass ? "PASS" : "FAIL");
    free(r);
}

int main(void) {
    int a[] = {2, 7, 11, 15};
    runTest(a, 4, 9, 0, 1);      /* typical case */

    int b[] = {3, 3};
    runTest(b, 2, 6, 0, 1);      /* edge: duplicates */

    int c[] = {-1, -2, -3, -4, -5};
    runTest(c, 5, -8, 2, 4);     /* edge: negatives */
    return 0;
}