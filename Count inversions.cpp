class Solution{
  public:
    
    long long merge(long long arr[], long long temp[], long long left, long long mid, long long right){
    
        long long i, j, k, count;
        i = left;
        j = mid;
        k = left;
        count = 0;
        
        while(i <=mid-1 && j <= right){
            if(arr[i] <= arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
                count += mid-i;
            }
        }
        
        while(i<= mid-1){
            temp[k++] = arr[i++];
        }
        
        while(j<= right){
            temp[k++] = arr[j++];
        }
        
        for(i = left; i<=right; i++){
            arr[i] = temp[i];
        }
        
        return count;
    }
    
    long long mergesort(long long arr[], long long temp[], long long start, long long end){
        if(start >= end){
            return 0;
        }
        
        long long mid = (start + end)/2;
        long long count =0;
        
        count += mergesort(arr, temp, start, mid);
        count += mergesort(arr, temp, mid+1, end);
        
        count += merge(arr, temp, start, mid+1, end);
        
        return count;
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        if(n == 0 || n == 1)
            return 0;
            
        long long temp[n];
        return mergesort(arr, temp, 0, n-1);
    }

};
