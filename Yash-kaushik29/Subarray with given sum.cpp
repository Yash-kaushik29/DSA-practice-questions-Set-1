class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        int start=0,last,flag=0;
        long long sum=0;
        vector<int> ans;
        
        if(s==0)
        ans.push_back(-1);
        
        else {
            for(int i=0; i<n; i++) {
            sum+=arr[i];
            
            while(sum>s) {
                sum-=arr[start];
                start++;
            }
            
            if(sum==s) {
                last=i+1;
                flag=1;
                break;
            }
        }
        
        if(flag==0) {
            ans.push_back(-1);
        }
        
        else {
        ans.push_back(start+1);
        ans.push_back(last);
        }
        }
        
        return ans;
    }
};
