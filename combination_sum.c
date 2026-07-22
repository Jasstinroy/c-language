#include <stdlib.h>

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* path, int pathSize,
               int*** result, int** columnSizes, int* returnSize) {

    if (target == 0) {
        (*result)[*returnSize] = (int*)malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++)
            (*result)[*returnSize][i] = path[i];

        (*columnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        // i instead of i+1 because same number can be reused
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i,
                  path, pathSize + 1,
                  result, columnSizes, returnSize);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    *returnSize = 0;

    // Maximum combinations < 150 (given in problem)
    int maxCombinations = 150;

    int** result = (int**)malloc(maxCombinations * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxCombinations * sizeof(int));

    // Maximum possible path length is target (minimum candidate is at least 1)
    int* path = (int*)malloc(target * sizeof(int));

    backtrack(candidates, candidatesSize, target, 0,
              path, 0,
              &result, returnColumnSizes, returnSize);

    free(path);

    return result;
}
