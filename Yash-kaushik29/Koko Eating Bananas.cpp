class Solution {
 public:   
   int minEatingSpeed(vector<int>& piles, int h) {
        int s=1,e=1e9;
        int n=piles.size();

        while(s<=e){

            long long hours=0;
            int mid=(s+e)/2;
            
            for(int i=0; i<n; i++){
                if(piles[i]%mid==0){
                    hours+=(piles[i]/mid);
                }
                else{
                    int x=piles[i]/mid;
                    x++;
                    hours+=x;
                }
            }
            if(hours<=h){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};
