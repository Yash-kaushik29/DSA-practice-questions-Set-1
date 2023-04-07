class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        
        int i=0, j=0, k=0;
        vector<pair<int, int> > dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        pair<int, int> ans;
        
        while(i>=0 and j>=0 and i<R and j<C) {
            
            // store last cell index
            ans = {i,j};
            
            if(matrix[i][j] == 1) {
                matrix[i][j] = 0;
                // change direction
                k = (k+1) % 4;
            }
            
            i += dir[k].first;
            j += dir[k].second;
        }
        
        return ans;
    }
};
