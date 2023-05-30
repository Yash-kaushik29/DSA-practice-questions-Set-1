class Solution {
public:
    bool search(int i, int j, int n, int m, vector<vector<char>>& board, string word, int k) {
        
        if(k == word.length()) return true;
        if(i<0 || i==n || j<0 || j==m || board[i][j]!=word[k]) return false;
        
        char ch = board[i][j];
        board[i][j]='@';
        
        bool down = search(i+1, j, n, m, board, word, k+1);
        bool right = search(i, j+1, n, m, board, word, k+1);
        bool up = search(i-1, j, n, m, board, word, k+1);
        bool left = search(i, j-1, n, m, board, word, k+1);
        
        board[i][j]=ch;
        return up || down || left || right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    if(search(i, j, n, m, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};
