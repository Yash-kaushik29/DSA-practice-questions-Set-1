class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
      long long sum=0;
         long long sum1=0;
         //int res=-1;
         
         if(n==1)
         return 1;
        
         for(int i=0 ; i<n ; i++)
         {
             sum+=a[i];
         }
         
         for(int i=0 ; i<n ; i++)
         {
            if(2*sum1 == (sum-a[i]))
            return i+1;
            sum1+=a[i];
         } 
         
        return -1;
    
    }
};
