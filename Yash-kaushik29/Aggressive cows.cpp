class Solution {
public:

    bool isPossible(int n, int k, vector<int> &stalls, int mid)  {
        
        int cow=1;
        int last=stalls[0];
        
        for(int i=0; i<stalls.size(); i++)  {
            
            if(stalls[i]-last>=mid) {
                
            cow++;
            if(cow==k)  {
            return true;
            }
            last=stalls[i];
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        if(n<k)  {
            return 0;
        }
        
        else  {
            
        int s=0;
        int ans=-1;
        
        sort(stalls.begin(),stalls.end());
        
        int e=stalls[n-1];
        int mid=s+(e-s)/2;
        
        while(s<=e)  {
            
            if(isPossible(n,k,stalls,mid))  {
                
                ans=mid;
                s=mid+1;
            }
            else  {
                
                e=mid-1;
            }
            
            mid=s+(e-s)/2;
        }
        return ans;
    }
  }
};
