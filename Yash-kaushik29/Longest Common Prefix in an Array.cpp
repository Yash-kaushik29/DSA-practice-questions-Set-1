class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string res="";
        sort(arr, arr+N);
        
        string a=arr[0];
        string b=arr[N-1];
        
        for(int i=0;i<arr[0].size();i++) {
            if(a[i]==b[i])
                res+=a[i];
            else
                break;
        }
        
        if(res.length() == 0) {
            return "-1";
        }
        
        return res;
    }
};
