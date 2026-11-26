#include <stdio.h>

/* LeetCode: Best Time to Buy and Sell Stock - single pass */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize < 2) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];              /* better day to buy */
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;  /* better profit if sold today */
        }
    }
    return maxProfit;
}

/* ---------- Local tests ---------- */
void runTest(int* prices, int n, int expected) {
    int result = maxProfit(prices, n);
    printf("profit = %d  expected %d  %s\n",
           result, expected, result == expected ? "PASS" : "FAIL");
}

int main(void) {
    int a[] = {7, 1, 5, 3, 6, 4};
    runTest(a, 6, 5);        /* typical case: buy at 1, sell at 6 */

    int b[] = {7, 6, 4, 3, 1};
    runTest(b, 5, 0);        /* edge: prices only fall, no profit */

    int c[] = {5};
    runTest(c, 1, 0);        /* edge: single day */

    int d[] = {2, 4, 1};
    runTest(d, 3, 2);        /* edge: lowest price comes after the peak */
    return 0;
}