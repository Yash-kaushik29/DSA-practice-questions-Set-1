class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid) {
        int dayCount=1;
        int weight=0;

        for(int i=0; i<weights.size(); i++) {
            if(weights[i]+weight <= mid) {
                weight+=weights[i];
            }
            else {
                dayCount++;
                weight=weights[i];
                if(dayCount>days || weights[i]>mid) {
                    return false;
                }
            }
        }
        return true;
    } 
    
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int sum=0;
        int ans=-1;

        for(int i=0; i<weights.size(); i++) {
            sum+=weights[i];
        }

        int e=sum;

        while(s<=e) {
            int mid=s+(e-s)/2;

            if(isPossible(weights, days, mid)) {
                ans=mid;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
    }
};
