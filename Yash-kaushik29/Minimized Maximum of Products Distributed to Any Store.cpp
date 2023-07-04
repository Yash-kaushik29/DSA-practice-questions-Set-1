#define ll long long
class Solution {
public:
    bool isPossible(int n, vector<int> quantities, int mid) {
        ll stores=0;

        for(int i=0; i<quantities.size(); i++) {
            stores += (quantities[i]+mid-1)/mid;

            if(stores > n) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        ll ans = 0;
        ll maxi = *max_element(quantities.begin(), quantities.end());

        ll s=1, e=maxi;

        while(s <= e) {
            ll mid = s+(e-s)/2;
 
            if(isPossible(n, quantities, mid)) {
                ans = mid;
                e = mid-1;
            }
            else {
                s = mid+1;
            }
        }

        return ans;
    }
};
