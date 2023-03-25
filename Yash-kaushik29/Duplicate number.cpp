class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         unordered_map<int,int> m;
         vector<int> v;
         int a;
        
       for(int i=0 ; i<nums.size() ; i++)
       {
           m[nums[i]]++;
       }
       
       for(auto it:m)
       {
           if(it.second > 1)
           a= it.first;
       }
       
       return a;
        
    }
};


// Approach 2

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int slow=nums[0];
      int fast=nums[0];

      do {
          slow = nums[slow];
          fast = nums[nums[fast]];
      }  while(slow != fast);

      slow=nums[0];

      while(slow != fast) {
          slow = nums[slow];
          fast = nums[fast];
      }

      return slow;
    }
};
