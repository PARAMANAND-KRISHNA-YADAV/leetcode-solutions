## Problem: Valid Anagram (Easy)
**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
If the lengths differ, the strings cannot be anagrams. Otherwise I use a
count array of 26 slots: increment for each letter in s and decrement for
each letter in t. If every count ends at zero, the strings are anagrams.

### Complexity
- Time: O(n)
- Space: O(1) (the count array is always size 26)

### Notes
Sorting both strings also works but costs O(n log n). The count array only
handles lowercase letters; for Unicode input I would use a hash map instead.