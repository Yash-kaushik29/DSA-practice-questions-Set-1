class Solution
{
    public:
        bool isPossible(int n, vector<int> a, int k, int w, long long int height) {
            
            for(int i=0; i<n; i++) {
                if(a[i] < height) {
                    int days = height - a[i];
                    if(days > k) return false;
                    k-=days;
                    a[i] = height;
                    
                    int j=i+1;
                    while(j<n and j<i+w) {
                        a[j]+=days;
                        j++;
                    }
                }
            }
            return true;
        }
      
      
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a) {
            
            long long int mini = *min_element(a.begin(), a.end());
            long long int maxi = mini+k;
            long long int ans;
            
            while(mini <= maxi) {
                long long int mid = (mini+maxi)/2;
                
                if(isPossible(n, a, k, w, mid)) {
                    ans = mid;
                    mini = mid+1;
                }
                else {
                    maxi = mid-1;
                }
            }
            return ans;
        }
};
