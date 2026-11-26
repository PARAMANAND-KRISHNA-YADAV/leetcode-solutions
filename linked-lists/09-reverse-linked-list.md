## Problem: Reverse Linked List (Easy)
**Link:** https://leetcode.com/problems/reverse-linked-list/

### Approach
Walked through the list once with three pointers: prev, curr and next. At each
node I saved the next node, pointed curr back at prev, then moved both
pointers forward. When curr becomes NULL, prev is the new head.

### Complexity
- Time: O(n)
- Space: O(1)

### Notes
Saving curr->next before changing it is essential, otherwise the rest of the
list is lost. An empty list and a single node both work without special cases.
A recursive version is shorter but uses O(n) stack space.