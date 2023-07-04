typedef long long ll;

class Solution {
public:
    bool isPossible(vector<int> &time, ll mid, ll t){
        ll trips = 0;
        for(auto &i:time){
            trips += (mid/i);
            if(trips >= t) return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        sort(time.begin(), time.end());

        ll l = (ll)time[0];
        ll r = (ll)time[n-1]*(ll)totalTrips;

        while(l <= r) {
            ll mid = l + (r-l)/2;

            if(isPossible(time, mid, (ll)totalTrips)){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};
