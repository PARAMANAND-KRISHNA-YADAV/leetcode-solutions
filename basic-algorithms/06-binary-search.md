## Problem: Binary Search (Easy)
**Link:** https://leetcode.com/problems/binary-search/

### Approach
Because the array is sorted, I compare the target with the middle element and
discard the half that cannot contain it. I repeat this with two pointers
(left and right) until the target is found or the pointers cross.

### Complexity
- Time: O(log n)
- Space: O(1)

### Notes
Computing mid as left + (right - left) / 2 avoids integer overflow with very
large indices. The loop condition is left <= right so that a single remaining
element is still checked. Off-by-one errors with mid + 1 and mid - 1 are the
most common bug here.