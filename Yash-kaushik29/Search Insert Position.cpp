class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

       int s = 0;
       int e = nums.size();
       int ans = 0; 

       if(target > nums[e-1])
         return e;

       if(target < nums[0])
         return 0;  

       while(s < e) {
          
          int mid = s+(e-s)/2;
          if(nums[mid] == target)
            return mid;

          else if(nums[mid] < target) {
              ans = mid+1;
              s = mid+1;
          } 

          else 
              e = mid;               
       }
       return ans; 
    }
};
