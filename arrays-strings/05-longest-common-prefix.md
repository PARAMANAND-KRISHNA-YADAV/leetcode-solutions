## Problem: Longest Common Prefix (Easy)
**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Used vertical scanning: take each character position of the first string and
compare it with the same position in every other string. I stop at the first
mismatch or when any string ends, then copy that many characters as the result.

### Complexity
- Time: O(S), where S is the total number of characters in all strings
- Space: O(1) extra, apart from the returned prefix string

### Notes
Checking for '\0' in the other strings prevents reading past a shorter string.
An empty string in the list gives an empty prefix. The result must be
malloc'd because C cannot return a local array.