class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        
        // Your logic here
        int count=0;
        int res=a^b;
        while(res>0) {
            count++;
            res=res & (res-1);
        }
        
        return count;
    }
};
