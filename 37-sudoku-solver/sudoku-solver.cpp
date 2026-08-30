class Solution {
public:
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                // Skip filled cells
                if (board[row][col] != '.')
                    continue;

                // Try digits 1 to 9
                for (char num = '1'; num <= '9'; num++) {

                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        // Recursively solve remaining cells
                        if (solve(board))
                            return true;

                        // Undo if this choice doesn't work
                        board[row][col] = '.';
                    }
                }

                // No number works here
                return false;
            }
        }

        // All cells are filled
        return true;
    }

    bool isValid(vector<vector<char>>& board,
                 int row, int col, char num) {

        for (int i = 0; i < 9; i++) {

            // Check row
            if (board[row][i] == num)
                return false;

            // Check column
            if (board[i][col] == num)
                return false;

            // Check 3x3 box
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;

            if (board[boxRow][boxCol] == num)
                return false;
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};