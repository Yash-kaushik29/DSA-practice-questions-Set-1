class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int bit=1<<i;
            int c=0;
            for(int j:nums)
            {
                if(j&bit)
                c++;
            }
            if(c%3)
            ans|=bit;
        }
        return ans;
    }
};
