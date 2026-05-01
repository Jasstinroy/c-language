#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* countAndSay(int n) {
    char *result = (char*)malloc(2);
    strcpy(result, "1");

    for (int i = 2; i <= n; i++) {
        int len = strlen(result);
        char *temp = (char*)malloc(len * 2 + 1); 
        int pos = 0;

        for (int j = 0; j < len; ) {
            char current = result[j];
            int count = 0;

            while (j < len && result[j] == current) {
                j++;
                count++;
            }

            pos += sprintf(temp + pos, "%d%c", count, current);
        }

        free(result);
        result = temp;
    }

    return result;
}
