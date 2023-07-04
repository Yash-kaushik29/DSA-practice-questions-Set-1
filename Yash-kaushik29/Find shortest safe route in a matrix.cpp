class Solution
{
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<4;k++){
                        int cx = i + dx[k];
                        int cy = j + dy[k];
                        if(cx>=0 && cy>=0 && cx<n && cy<m && mat[cx][cy]==1) mat[cx][cy] = -1;
                    }
                }
            }
        }
     
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            if(mat[i][0]==1){
                q.push({i,0,1});
                mat[i][0]=-1;
            }
        }
        
        while(!q.empty()){
            vector<int> it = q.front();
            q.pop();
            
            if(it[1] == m-1) return it[2];
            
            for(int k=0;k<4;k++){
                int cx = it[0] + dx[k];
                int cy = it[1] + dy[k];
                if(cx>=0 && cy>=0 && cx<n && cy<m && mat[cx][cy]==1){
                    mat[cx][cy] = -1;
                    q.push({cx,cy,it[2]+1});
                }  
            }
        }
        return -1;   
    }
};
