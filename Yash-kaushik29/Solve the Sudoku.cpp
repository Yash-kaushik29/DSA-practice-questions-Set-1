class Solution 
{
    public:
    bool isSafe(int r, int c, int grid[N][N], int val) {
        
        for(int i=0; i<9; i++) {
            // check for row and column
            if((grid[i][c] == val) || (grid[r][i] == val)) {
                return false;
            }
            
            // check for 3x3 matrix
            if(grid[3*(r/3) + i/3][3*(c/3) + i%3] == val) {
                return false;
            }
        }
        return true;
    }
    
     
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                
                // cell empty
                if(grid[i][j] == 0) {
                    for(int val=1; val<=9; val++) {
                        if(isSafe(i, j, grid, val)) {
                            
                            grid[i][j] = val;
                            bool next = SolveSudoku(grid);
                            
                            if(next) 
                              return true;
                            else
                              // backtrack
                              grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        SolveSudoku(grid);
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
