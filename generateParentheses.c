#include <stdlib.h>
#include <string.h>

void backtrack(char **res, int *returnSize, char *curr, int pos, int open, int close, int n) {
    if (pos == 2*n) {
        curr[pos] = '\0';
        res[*returnSize] = malloc((2*n+1) * sizeof(char));
        strcpy(res[*returnSize], curr);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        curr[pos] = '(';
        backtrack(res, returnSize, curr, pos+1, open+1, close, n);
    }

    if (close < open) {
        curr[pos] = ')';
        backtrack(res, returnSize, curr, pos+1, open, close+1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **res = malloc(15000 * sizeof(char*));
    char curr[20];

    *returnSize = 0;
    backtrack(res, returnSize, curr, 0, 0, 0, n);

    return res;
}
