#include <string.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if (numRows == 1 || numRows >= len)
        return s;

    char** rows = (char**)malloc(numRows * sizeof(char*));
    int* rowSizes = (int*)calloc(numRows, sizeof(int));

    for (int i = 0; i < numRows; i++)
        rows[i] = (char*)malloc((len + 1) * sizeof(char));

    int currentRow = 0;
    int goingDown = 0;

    for (int i = 0; i < len; i++) {
        rows[currentRow][rowSizes[currentRow]++] = s[i];

        if (currentRow == 0 || currentRow == numRows - 1)
            goingDown = !goingDown;

        currentRow += goingDown ? 1 : -1;
    }

    char* result = (char*)malloc((len + 1) * sizeof(char));
    int pos = 0;

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < rowSizes[i]; j++)
            result[pos++] = rows[i][j];
        free(rows[i]);
    }

    result[pos] = '\0';

    free(rows);
    free(rowSizes);

    return result;
}
