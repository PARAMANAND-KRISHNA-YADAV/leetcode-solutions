#include <stdio.h>

/* LeetCode: Binary Search (#704) - iterative */
int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;   /* avoids overflow */
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

/* ---------- Local tests ---------- */
void runTest(int* nums, int n, int target, int expected) {
    int result = search(nums, n, target);
    printf("target=%d -> index %d  expected %d  %s\n",
           target, result, expected, result == expected ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {-1, 0, 3, 5, 9, 12};
    runTest(a, 6, 9, 4);      /* typical case: found */
    runTest(a, 6, 2, -1);     /* typical: not found */
    runTest(a, 6, -1, 0);     /* edge: first element */
    runTest(a, 6, 12, 5);     /* edge: last element */

    int b[] = {5};
    runTest(b, 1, 5, 0);      /* edge: single element, found */
    runTest(b, 1, 3, -1);     /* edge: single element, not found */
    return 0;
}