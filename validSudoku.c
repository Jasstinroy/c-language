#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            
            if (board[i][j] == '.')
                continue;
            
            int num = board[i][j] - '1';  // 0 to 8
            int k = (i / 3) * 3 + (j / 3);  // box index
            
            if (row[i][num] || col[j][num] || box[k][num])
                return false;
            
            row[i][num] = 1;
            col[j][num] = 1;
            box[k][num] = 1;
        }
    }
    
    return true;
}
