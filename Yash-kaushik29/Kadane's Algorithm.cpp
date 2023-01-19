class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int cur=0;
        int max=INT_MIN;
        
        for(int i=0 ; i<n ; i++)
        {
            cur=cur+arr[i];
            
            if(cur>max)
            {
                max=cur;
            }
            
            if(cur<0)
            {
                cur=0;
            }
        }
        
        return max;
        
    }
};
