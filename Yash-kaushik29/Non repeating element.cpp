class Solution{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
        // Complete the function
        unordered_map<int,int> m;
          int a=0;
        for(int i=0 ; i<n ; i++)
        {
            m[arr[i]]++;
        }
         
        for(int i=0 ; i<n ; i++)
        {
            if(m[arr[i]]==1) {
            a=arr[i];
            break;
            }
        }
        
       return a;
        
    } 
  
};
