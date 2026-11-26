## Problem: Reverse String (Easy)
**Link:** https://leetcode.com/problems/reverse-string/

### Approach
Used two pointers, one at the start and one at the end, swapping the
characters and moving inward until they meet. This reverses the string in
place without a second array.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
The loop condition is left < right, so the middle character of an odd-length
string is never swapped with itself. Empty and single-character strings work
without any special case.