class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int s=0;
        int e=arr.size();

        while(s < e) {
            int mid = s+(e-s)/2;

            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) {
                return mid;
            }
            else if(arr[mid]>arr[mid-1]) {
                s=mid;
            }
            else {
                e=mid;
            }
        }
        return -1;
          
    }
};
