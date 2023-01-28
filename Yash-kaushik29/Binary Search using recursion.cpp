int binary_search(int arr[], int s , int e, int key) {
    
    // element not found
    if(s>e) return -1;

    // element found
    int mid=s+(e-s)/2;
    if(arr[mid]==key) return mid;

    if(arr[mid]<key) {
        return binary_search(arr,mid+1,e,key);
    }

    else {
        return binary_search(arr,0,mid-1,key);
    }
}

int binarySearch(int *input, int n, int val)
{
    //Write your code here
    int ans=binary_search(input,0,n-1,val);
    return ans;
}
