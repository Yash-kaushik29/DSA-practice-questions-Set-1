class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size()-1;
        int carry = 0;

        while(i>=0) {
            int sum = nums[i] + (k%10) + carry;
            k=k/10;

            nums[i--] = sum%10;
            carry = sum/10;
        }

        while(k>0) {
            int sum = (k%10) + carry;
            k=k/10;

            nums.insert(nums.begin(), sum%10);
            carry = sum/10;
        }

        if(carry) {
            nums.insert(nums.begin(), carry);
        }

        return nums;
    }
};
