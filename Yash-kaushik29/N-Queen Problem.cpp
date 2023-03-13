class Solution{
public:
    void addsolution(vector<vector<int>> board, vector<vector<int>> &ans, int n) {
        vector<int> temp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                
                if(board[i][j] == 1)
                  temp.push_back(j+1);
            }
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int r, int c, vector<vector<int>> board, int n) {
        
        int i=r;
        int j=c;
        
        // Check for same column
        while(i>=0) {
            if(board[i][j] == 1)
              return false;
            i--;  
        }
        
        // check for left diagonal
        i=r;
        j=c;
        
        while(i>=0 && j>=0) {
            if(board[i][j] == 1)
              return false;
            i--;
            j--;
        }
        
        // chek for right diagonal
        i=r;
        j=c;
        
        while(i>=0 && j<n) {
            if(board[i][j] == 1)
              return false;
            i--;
            j++;
        }
        return true;
    }

    void solve(int row, vector<vector<int>> &ans, vector<vector<int>> board, int n) {
        
        // base case
        if(row == n) {
            addsolution(board, ans, n);
            return ;
        }
        
        for(int col=0; col<n; col++) {
            if(isSafe(row, col, board, n)) {
                board[row][col] = 1;
                solve(row+1, ans, board, n);
                board[row][col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        
        solve(0, ans, board, n);
        
        return ans;
    }
};
