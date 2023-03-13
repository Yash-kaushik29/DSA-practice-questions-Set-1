class Solution{
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m) {
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1) {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    void solve(int n, vector<vector<int>> &m, vector<string>& ans, int x, int y, vector<vector<int>> &visited, string path) {
       
       //Base case
       if(x==n-1 && y==n-1) {
           ans.push_back(path);
           return;
       }
       
       visited[x][y]=1;
       
       // 4 Choices:: L/ R/ D/ U
       // Down condition
       int newx=x+1;
       int newy=y;
       if(isSafe(newx, newy, n, visited, m)) {
           path.push_back('D');
           solve(n, m, ans, newx, newy, visited, path);
           path.pop_back();
       }
       
       // Left condition
       newx=x;
       newy=y-1;
       if(isSafe(newx, newy, n, visited, m)) {
           path.push_back('L');
           solve(n, m, ans, newx, newy, visited, path);
           path.pop_back();
       }
       
       // Right condition
       newx=x;
       newy=y+1;
       if(isSafe(newx, newy, n, visited, m)) {
           path.push_back('R');
           solve(n, m, ans, newx, newy, visited, path);
           path.pop_back();
       }
       
       // Up condition
       newx=x-1;
       newy=y;
       if(isSafe(newx, newy, n, visited, m)) {
           path.push_back('U');
           solve(n, m, ans, newx, newy, visited, path);
           path.pop_back();
       }
       
       visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        // If first cell is 0, no path is possible
        if(m[0][0]==0) {
            return ans;
        }
        
        int srcx=0;
        int srcy=0;
        
        vector<vector<int>> visited=m;
        // Initialise with zero
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                visited[i][j]=0;
            }
        }
        
        string path="";
        solve(n,m,ans,srcx,srcy,visited,path);
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
};


// Approach 2: Backtrack
class Solution{
    public:
    bool isSafe(int x, int y, vector<vector<int>> &m, int n, vector<vector<bool>> &visited) {
        
        if((x>=0 && x<n) && (y>=0 && y<n) && (visited[x][y] == 0) && m[x][y] ==1) {
            return true;
        }
        else
            return false;
    }
    
    void solve(int x, int y, vector<vector<int> > &m, int n, vector<string> &ans, vector<vector<bool>> &visited, string path) {
        
        // base case
        if((x == n-1) && (y == n-1)) {
            ans.push_back(path);
            return ;
        }
        
        visited[x][y] = 1;
        // Down movement
        if(isSafe(x+1, y, m, n, visited)) {
            solve(x+1, y, m, n, ans, visited, path + 'D');
        }
        
        // Left movement
        if(isSafe(x, y-1, m, n, visited)) {
            solve(x, y-1, m, n, ans, visited, path + 'L');
        }
        
        // Right movement
        if(isSafe(x, y+1, m, n, visited)) {
            solve(x, y+1, m, n, ans, visited, path + 'R');
        }
        
        // Up movement
        if(isSafe(x-1, y, m, n, visited)) {
            solve(x-1, y, m, n, ans, visited, path + 'U');
        }
        visited[x][y] = 0;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool> > visited(n, vector<bool>(n,0));
        string path = "";
        
        if(m[0][0] == 0)
           return ans;
        
        solve(0, 0, m, n, ans, visited, path);
    }
};
