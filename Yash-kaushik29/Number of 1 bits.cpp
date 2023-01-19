class Solution {
public:
    int hammingWeight(uint32_t n) {
        int setBits=0;
        while(n!=0){
            if( n & 1!=0)
                setBits++;
            n=n>>1;
        }
        return setBits;
    }
};
