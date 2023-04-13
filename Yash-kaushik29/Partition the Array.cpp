class Solution
{
public:
    int binarySearch(long long arr[], int low, int high, long long sum, long long temp) {
        int mid, index=-1;
        long long first, second, diff=INT_MAX;
        
        while(low <= high) {
            mid = low + (high-low)/2;
            
            first = arr[mid] - temp;
            second = sum - arr[mid];
            
            if(abs(first - second) < diff) {
                diff = abs(first - second);
                index = mid;
            }
            if(first < second) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return index;
    }

    long long minDifference(int N, vector<int> &A) {
        long long arr[N];
        
        arr[0] = A[0];
        for(int i=1; i<N; i++) {
            arr[i] = A[i] + arr[i-1];
        }
        
        long long w, x, y, z, ans=INT_MAX;
        
        for(int i=2; i<N-1; i++) {
            int index = binarySearch(arr, 0, i-1, arr[i-1], 0);
            
            w = arr[index];
            x = arr[i-1] - w;
            
            index = binarySearch(arr, i, N-1, arr[N-1], arr[i-1]);
            
            y = arr[index] - arr[i-1];
            z = arr[N-1] - arr[index];
            
            ans = min(ans, max({w,x,y,z}) - min({w,x,y,z}));
        }
        return ans;
    }
};
