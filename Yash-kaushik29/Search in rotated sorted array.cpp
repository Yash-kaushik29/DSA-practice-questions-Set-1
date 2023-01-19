class Solution {
public:
    int get_pivot(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;

        int mid=s+(e-s)/2;

        while(s<e) {
            if(nums[mid]>=nums[0]) {
                s=mid+1;
            }

            else{
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    
    int binary_search(vector<int>& nums,int start, int end, int target) {
        int s=start;
        int e=end;

        int mid=s+(e-s)/2;

        while(s<=e) {
            if(target==nums[mid]) 
            return mid;

            else if(target>nums[mid])
            s=mid+1;

            else
            e=mid-1;

            mid=s+(e-s)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivot=get_pivot(nums);
        int n=nums.size();

        if(target>=nums[pivot] && target<=nums[n-1])
        return binary_search(nums,pivot,n-1,target);

        else
        return binary_search(nums,0,pivot-1,target);

    }
};
