vector<int> find(int arr[], int n , int x )
{
    // code here
    
        vector<int> v;
    int start = 0 ;
    int end = n-1;
    int mid  = start + (end-start)/2;
    
    int first = -1;
    int last = -1;
    
    while(start<=end){
        if(x == arr[mid]){
            first= mid;
            end = mid-1;
        }
        else
        if(x<arr[mid])
            end = mid - 1;
        else
        if(x>arr[mid])
            start = mid + 1;
        
        mid = start + (end-start)/2;
    }
    v.push_back(first);
    
    start = 0 ;
    end = n-1;
    mid  = start + (end-start)/2;
    
    while(start<=end){
        if(x == arr[mid]){
            last = mid;
            start = mid+1;
        }
        else
        if(x<arr[mid])
            end = mid - 1;
        else
        if(x>arr[mid])
            start = mid + 1;
        
        mid = start + (end-start)/2;
    }
    v.push_back(last);
    return v;
   }
