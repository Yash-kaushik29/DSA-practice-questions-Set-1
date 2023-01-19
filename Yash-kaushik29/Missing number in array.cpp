class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int ans=0;
       for(int i=0 ; i<=n ; i++)
        {
            ans=ans^i;
        }
        
        for(int i=0 ; i<n-1 ; i++)
        {
            ans=ans^array[i];
        }
        
        
       
        return ans;
    }
};
