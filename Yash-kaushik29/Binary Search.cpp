class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int k) 
    { 
    
       // Your code here
       int start=0;
       int end=N-1;
     //  int ans=-1;
       
       int mid=(start+end)/2;
       
       while(start<=end)
       {
            if(k==arr[mid])
            return 1;
            
            else if(k>arr[mid])
            start=mid+1;
            
            else
            end=mid-1;
            
            mid=(start+end)/2;
       }
       
      return -1;
     }
  };
