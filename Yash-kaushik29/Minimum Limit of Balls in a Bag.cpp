// Binary search approach

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int e= *max_element(nums.begin(),nums.end());
        int s=1;
        int ans;

        if(maxOperations==1 && nums[0]>1)
        return nums[0]/2;

        if(maxOperations==1 && nums[0]==1)
        return nums[0]; 

        while(s<=e) {
            int penalty=s+(e-s)/2;
            int operations=0;

            for(int i=0; i<nums.size(); i++) {
                if(nums[i]>penalty) {
                    if(nums[i]%penalty==0) {
                    operations+=(nums[i]/penalty)-1;
                    }
                    else {
                    operations+=nums[i]/penalty;
                }
              }
            }
            if(operations <= maxOperations) {
                ans=penalty;
                e=penalty-1;
            }

            else {
                s=penalty+1;
            }
        }

        return ans;

    }
};


// Optimised binary search

class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int right = INT_MAX;
        int cnt = 0,ans = 0, left = 1,mid;
        while(left < right){
            mid = ((right-left)>>1)+left;
            cnt = 0;
            for(auto &i: nums){
                cnt += ((i-1)/mid);
            }
            if(cnt>k){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
