#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* LeetCode: Longest Common Prefix - vertical scanning */
char* longestCommonPrefix(char** strs, int strsSize) {
    int prefixLen = 0;

    if (strsSize > 0) {
        int len = (int)strlen(strs[0]);
        for (int i = 0; i < len; i++) {
            char c = strs[0][i];
            int allMatch = 1;
            for (int j = 1; j < strsSize; j++) {
                if (strs[j][i] == '\0' || strs[j][i] != c) {
                    allMatch = 0;
                    break;
                }
            }
            if (!allMatch) break;
            prefixLen++;
        }
    }

    char* result = (char*)malloc(prefixLen + 1);
    if (prefixLen > 0) memcpy(result, strs[0], prefixLen);
    result[prefixLen] = '\0';
    return result;
}

/* ---------- Local tests ---------- */
void runTest(char** strs, int n, const char* expected) {
    char* result = longestCommonPrefix(strs, n);
    printf("prefix = \"%s\"  expected \"%s\"  %s\n",
           result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");
    free(result);
}

int main(void) {
    char* a[] = {"flower", "flow", "flight"};
    runTest(a, 3, "fl");        /* typical case */

    char* b[] = {"dog", "racecar", "car"};
    runTest(b, 3, "");          /* edge: no common prefix */

    char* c[] = {"alone"};
    runTest(c, 1, "alone");     /* edge: single string */

    char* d[] = {"", "b"};
    runTest(d, 2, "");          /* edge: empty string in the list */

    char* e[] = {"ab", "ab"};
    runTest(e, 2, "ab");        /* edge: identical strings */
    return 0;
}