## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
Checked every pair of elements using two nested loops and returned the
indices of the first pair that adds up to the target. It is simple and
needs no extra data structures.

### Complexity
- Time: O(n^2)
- Space: O(1) (excluding the 2-element result array)

### Notes
Duplicates like [3,3] work because j starts at i+1. A hash map would bring
this down to O(n) time; I want to try that next time.