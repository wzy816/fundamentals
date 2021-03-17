/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1
*/

class Solution {
int total = 0;
int n2;
int n1;
public:
    int totalNQueens(int n) {
      n2 = n*n;
      n1 = n;
        for(int i= 0;i<n;++i){
          // iterate first row
          vector<int> board(n2, 0);
          board[i] = 2;
          fill(board, 0,i);
          helper(board, n-1);
        }
        return total;
    }

    void helper(vector<int> & board, int left){
      if(left == 0){
        total +=1;
        // cout <<  "Solution\n";
        // print(board);
        return;
      }
      // search for empty slots in next row
      for(int col=0;col< n1;col++){
        int i=(n1-left)*n1+col;
        if(board[i]==0){
          // create new board
          vector<int> new_board(n2); 
          copy(board.begin(), board.end(), new_board.begin()); 
          new_board[i] = 2;
          fill(new_board, (int)i/n1, i%n1);
          // search further
          helper(new_board, left -1);
        }   
      }
    }

    void print(vector<int> & board){
      for(int i =0;i<n1;i++){
        for(int j=0;j<n1;j++){
          cout << board[i*n1+j] << " ";
        }
        cout << "\n";
      }
      cout << "\n";
    }
    void fill(vector<int> & board, int row, int col){
      // cout << row <<  col << "\n";
      // print(board);

      
      // fill row
      for(int i = row*n1;i<(row+1)*n1;++i){
        if(board[i] == 0) board[i] = 1;
      }
      
      // fill col
      for(int i = 0;i<n1;++i){
        if(board[i*n1+col] == 0) board[i*n1+col] = 1;
      }
      
      // fill diagnal
      int i = row; int j = col;
      while(i >=0 && j >=0){
        if(board[i*n1+j] == 0) board[i*n1+j] = 1;
        i--;j--;
      }
      i = row; j = col;
      while(i >=0 && j < n1){
        if(board[i*n1+j] == 0) board[i*n1+j] = 1;
        i--;j++;
      }
      i = row; j = col;
      while(i < n1 && j >= 0){
        if(board[i*n1+j] == 0) board[i*n1+j] = 1;
        i++;j--;
      }
      i = row; j = col;
      while(i <n1 && j < n1){
        if(board[i*n1+j] == 0) board[i*n1+j] = 1;
        i++;j++;
      }
      // cout << "after \n";
      // print(board);
       return;
    }
};
