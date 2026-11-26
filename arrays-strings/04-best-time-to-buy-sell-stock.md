## Problem: Best Time to Buy and Sell Stock (Easy)
**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach
Scanned the prices once while tracking the lowest price seen so far. For each
day, I checked what the profit would be if I sold that day after buying at the
lowest earlier price, and kept the maximum. This avoids checking every pair.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
The buy day must come before the sell day, so tracking the minimum so far
handles that. If prices only decrease, the answer stays 0. A brute-force
nested loop is O(n^2) and times out on large inputs.