class Solution
{
  public:
  
    bool isPossible(int arr[], int n, int k, long long mid)  {
        
        int painters=1;
        int sum=0;
        
        for(int i=0; i<n ; i++)  {
            
            sum+=arr[i];
            if(sum>mid)  {
            
            painters++;
            sum=arr[i];
            }
            
            if(painters>k)  return false;
        }
        return true;
    }
  
  
    long long minTime(int arr[], int n, int k)
    {
      
      long long maxi=0;
      long long sum=0;
      
      for(int i=0 ; i<n ; i++) {   
          
       maxi=max(maxi, 1LL *arr[i]);
         
         sum+=1LL * arr[i];  
      }
      
      long long s=maxi;
      long long e=sum;
      
      long long mid=s+(e-s)/2;
      
      while(s<=e)  {
          
          if(isPossible(arr,n,k,mid))  {
              e=mid-1;
          }
          else {
              s=mid+1;
          }
          mid=s+(e-s)/2;
      }
      return s;
    }
};
