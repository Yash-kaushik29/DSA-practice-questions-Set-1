class Solution {
public:
    #define ll long long 
    int minimizedMaximum(int n, vector<int>& quantities) {
     ll ans=0;
     ll maxi=-1;

     for(auto it:quantities) 
     maxi=max(maxi,(ll)it);

     ll s=1,e=maxi;

     while(s<=e) {
         ll mid=s+(e-s)/2;
         ll curStores=0;
         for(int i=0; i<quantities.size(); i++) {
             ll stores=(quantities[i] + mid-1)/mid;
             curStores+=stores;
         }

         if(curStores<=n) {
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
