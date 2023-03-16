class Solution {
public:

    bool isPossible(int n, int k, vector<int> &stalls, int mid)  {
        
        int cows=1;
        int last=stalls[0];
        
        for(int i=1; i<stalls.size(); i++) {
            if(stalls[i]-last >= mid) {
                cows++;
                if(cows == k)  return true;
                last = stalls[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        
        int ans=-1;
        int s=0;
        int e=stalls[n-1];
        
        while(s<=e) {
            int mid = s+(e-s)/2;
            
            if(isPossible(stalls,k,mid)) {
                ans=mid;
                s=mid+1;
            }
            else {
                e=mid-1;
            }
        }
        
        return ans;
  }
};
