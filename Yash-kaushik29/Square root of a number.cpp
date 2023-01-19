class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here 
        int s=0;
        int e=x;
        long long int m=s+(e-s)/2;
        long long int ans=-1;
        
        while(s<=e)
        {
            long long int square=m*m;
            
            if(square==x)
            return m;
            
            else if(square<x)
            {
              ans=m;
              s=m+1;
            }
            
            else
            {
                e=m-1;
            }
            m=s+(e-s)/2;
        }
        return ans;
    }
};
