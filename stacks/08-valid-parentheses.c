#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* LeetCode: Valid Parentheses (#20) - stack built on a char array */
bool isValid(char* s) {
    int len = (int)strlen(s);
    if (len % 2 != 0) return false;        /* odd length can never match */

    char* stack = (char*)malloc(len + 1);
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;              /* push opening bracket */
        } else {
            if (top == -1) {               /* closing bracket, nothing open */
                free(stack);
                return false;
            }
            char open = stack[top--];      /* pop the last opened bracket */
            if ((c == ')' && open != '(') ||
                (c == '}' && open != '{') ||
                (c == ']' && open != '[')) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);              /* valid only if nothing is left open */
    free(stack);
    return valid;
}

/* ---------- Local tests ---------- */
void runTest(char* s, bool expected) {
    bool result = isValid(s);
    printf("\"%s\" -> %s  expected %s  %s\n",
           s,
           result ? "true" : "false",
           expected ? "true" : "false",
           result == expected ? "PASS" : "FAIL");
}

int main(void) {
    runTest("()[]{}", true);     /* typical case: valid */
    runTest("(]", false);        /* typical: wrong type of closer */
    runTest("{[]}", true);       /* edge: nested */
    runTest("(", false);         /* edge: single opening bracket */
    runTest("]", false);         /* edge: closing with nothing open */
    runTest("([)]", false);      /* edge: interleaved */
    return 0;
}