/*
37. Sudoku Solver
Hard

2596

102

Add to List

Share
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


Input: board = [
["5","3",".",".","7",".",".",".","."],
["6",".",".","1","9","5",".",".","."],
[".","9","8",".",".",".",".","6","."],
["8",".",".",".","6",".",".",".","3"],
["4",".",".","8",".","3",".",".","1"],
["7",".",".",".","2",".",".",".","6"],
[".","6",".",".",".",".","2","8","."],
[".",".",".","4","1","9",".",".","5"],
[".",".",".",".","8",".",".","7","9"]
]

Output: [
["5","3","4","6","7","8","9","1","2"],
["6","7","2","1","9","5","3","4","8"],
["1","9","8","3","4","2","5","6","7"],
["8","5","9","7","6","1","4","2","3"],
["4","2","6","8","5","3","7","9","1"],
["7","1","3","9","2","4","8","5","6"],
["9","6","1","5","3","7","2","8","4"],
["2","8","7","4","1","9","6","3","5"],
["3","4","5","2","8","6","1","7","9"]
]

Explanation: The input board is shown above and the only valid solution is shown below:
*/

class Solution {

public:
    bool solved=false;

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0,0);
    }
    
    void backtrack(vector<vector<char>>& board, int row, int col){
        if(solved){
            return;
        }else if(row == 9 && col == 0){
            solved = true;
        }else if(col == 9){
            backtrack(board, row+1,0);
        }else if(board[row][col] != '.'){
            backtrack(board, row, col+1);
        }else{
            vector<int> c(10,0);
            for(int i=0;i<9;++i){
                // search row
                char num = board[row][i];
                if(num != '.'){
                    c[num-'0'] = 1;
                }
                // search col
                char num2 = board[i][col];
                if(num2 != '.'){
                    c[num2-'0'] = 1;
                }
                // search sub grid
                char num3 = board[row - row%3+int(i/3)][col - col%3+i%3];
                if(num3 != '.'){
                   c[num3-'0'] = 1;
                }      
            }

            for(int i=1;i<10;++i){
                if(c[i] == 0){
                    board[row][col] = i+'0';
                    backtrack(board, row, col+1);
                    if(solved){
                        return;
                    }
                    board[row][col] = '.';
                }
            }
        }
    }
};
