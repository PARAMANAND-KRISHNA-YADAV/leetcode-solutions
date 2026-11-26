#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* LeetCode: Valid Anagram - frequency count of 26 letters */
bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;

    int count[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) return false;
    }
    return true;
}

/* ---------- Local tests ---------- */
void runTest(char* s, char* t, bool expected) {
    bool result = isAnagram(s, t);
    printf("\"%s\" vs \"%s\" -> %s  expected %s  %s\n",
           s, t,
           result ? "true" : "false",
           expected ? "true" : "false",
           result == expected ? "PASS" : "FAIL");
}

int main(void) {
    runTest("anagram", "nagaram", true);   /* typical case */
    runTest("rat", "car", false);          /* typical: not anagram */
    runTest("a", "a", true);               /* edge: single character */
    runTest("ab", "abc", false);           /* edge: different lengths */
    runTest("aabb", "abab", true);         /* edge: duplicate letters */
    return 0;
}