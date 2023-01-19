class Solution 
{
    public:
    
    bool isPossible(int arr[], int n, int m, int mid)
    {
       int pagesum=0;
       int student=1;
       
       for(int i=0 ; i<n ; i++) 
       {
           if(pagesum + arr[i] <= mid)
           {
               pagesum+=arr[i];
           }
           else
           {
               student++;
               if( student>m || arr[i]>mid)
               {
                   return false;
               }
               pagesum=arr[i];
           }
       }
       return true;
    }
    
    
    //Function to find minimum number of pages.
    
    
    int findPages(int arr[], int n, int m) 
    {
        int s=0;
        int sum=0;
        int ans=-1;
        
        if(n<m)
        {
            return -1;
        }
        
        for(int i=0 ; i<n ;i++) 
        {
           sum+=arr[i]; 
        }
        
        int e=sum;
        int mid=s+(e-s)/2;
        
        while(s<=e)
        {
            if(isPossible(arr,n,m,mid))
            {
                ans=mid;
                e=mid-1;
            }
            
            else
            {
                s=mid+1;
            }
            
            mid=s+(e-s)/2;
        }
        
        return ans;
        
    }
};
