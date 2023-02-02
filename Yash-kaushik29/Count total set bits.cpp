//  Video solution : https://youtu.be/PM2v-6wtOEM


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if(n==0)
        return 0;
        
        if(n==1)
        return 1;
        
        int sq=1,i=-1;
        
        while(sq<=n) {
            sq*=2;
            i++;
        }
        
        sq=sq/2;
        int ans=(sq/2)*i + (n-sq+1) + countSetBits(n-sq);
        return ans;
    }
};
