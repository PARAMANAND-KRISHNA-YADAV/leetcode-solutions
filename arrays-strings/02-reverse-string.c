#include <stdio.h>
#include <string.h>

/* LeetCode: Reverse String - two pointers, in place */
void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

/* ---------- Local tests ---------- */
void runTest(char* input, const char* expected) {
    char buf[100];
    strcpy(buf, input);
    reverseString(buf, (int)strlen(buf));
    printf("\"%s\" -> \"%s\"  expected \"%s\"  %s\n",
           input, buf, expected, strcmp(buf, expected) == 0 ? "PASS" : "FAIL");
}

int main(void) {
    runTest("hello", "olleh");       /* typical case */
    runTest("a", "a");               /* edge: single character */
    runTest("", "");                 /* edge: empty string */
    runTest("abba", "abba");         /* edge: palindrome / even length */
    return 0;
}