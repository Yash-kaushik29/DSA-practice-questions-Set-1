class Solution{
public:
    bool check(vector<vector<int>>& board, int row, int col, int c) {
        // change value of curr cell to -1 so its value is not equal to c  
        board[row][col] = -1;

        for(int i=0;i<9;i++){
            if(board[i][col]==c)
            return false;

            if(board[row][i]==c)
            return false;

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            return false;
         }
         
             board[row][col] = c;

            return true;
    }

    int isValid(vector<vector<int>> board){
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                
                if(board[i][j]!=0) {
                    
                    if(!check(board, i, j, board[i][j])){
                        return false;
                    }
               }
            }
        }
        return true;
    }
};
