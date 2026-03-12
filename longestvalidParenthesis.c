#include <string.h>

int longestValidParentheses(char* s) {
    int stack[30001];
    int top = -1;

    stack[++top] = -1;   // base index
    int maxLen = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;

            if (top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if (len > maxLen)
                    maxLen = len;
            }
        }
    }

    return maxLen;
}
