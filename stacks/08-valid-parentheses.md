## Problem: Valid Parentheses (Easy)
**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
Used a stack. Every opening bracket is pushed, and every closing bracket must
match the bracket on top of the stack, which is then popped. If a closer
doesn't match, or the stack is empty when a closer arrives, the string is
invalid. At the end the stack must be empty.

### Complexity
- Time: O(n)
- Space: O(n)

### Notes
A quick early exit: an odd-length string can never be valid. The stack handles
nesting like "{[]}" and rejects interleaving like "([)]". Forgetting the final
"stack must be empty" check would wrongly accept inputs like "(((".