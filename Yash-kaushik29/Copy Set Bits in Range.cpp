class Solution{
    public:
    int setSetBit(int x, int y, int l, int r){
        // code here
        while(r>=l) {
            int mask=1<<(r-1);
            
            if(y & mask)
            x = x | mask;
            r--;
        }
        return x;
    }
};
