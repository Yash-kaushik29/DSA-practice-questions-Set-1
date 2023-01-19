class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int ans=0;
        int n=nums.size();
        if(n==1) return ans;

        //check if first or last element are peak
         if(nums[0]>nums[1]) return 0;
         if(nums[n-1]>nums[n-2]) return n-1;

         //search in the remaining array
            int start=1;
            int end=n-2;

            while(start<=end)
            {
                int mid=start+(end-start)/2;
                if(nums[mid]>nums[mid+1] && nums[mid]> nums[mid-1])  return mid; //if index found
                else if(nums[mid]<nums[mid+1])   start=mid+1; //search in upward slope
                else if(nums[mid]>nums[mid+1])   end=mid;//search in downward slope
            }
        return ans;
        
    }
};
