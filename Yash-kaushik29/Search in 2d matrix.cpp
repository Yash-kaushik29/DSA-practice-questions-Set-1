class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row=matrix.size();
        int col=matrix[0].size();

        int r=0;
        int c=col-1;

        while(r<row && c>=0) {
            int element=matrix[r][c];

            if(target == element) 
            return 1;

            else if(target > element)
            r++;

            else
            c--;
        }
        return 0;
    }
};
