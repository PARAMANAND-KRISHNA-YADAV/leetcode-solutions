## Problem: Move Zeroes (Easy)
**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
Used two pointers. One pointer scans the array, and another marks where the
next non-zero value should go. Each time the scanner finds a non-zero, I swap
it into that position and advance the marker, so all zeroes end up at the end
while the non-zero values keep their original order.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
This works in place with a single pass. If the array has no zeroes, the
swaps just swap each element with itself, which is harmless. A version that
only swaps when i != insertPos would avoid those redundant swaps.