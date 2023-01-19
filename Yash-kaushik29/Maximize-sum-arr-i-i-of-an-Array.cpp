class Solution {
   public:
       int Maximize(int a[],int n)
        {
        // Complete the function
        
         sort(a,a+n);
        long sum=0;
        
        for(int i=0; i<n; i++)
        {
            sum+=(long)a[i]*i;
        }
        return (int)(sum%(1000000007));
        }
     };
