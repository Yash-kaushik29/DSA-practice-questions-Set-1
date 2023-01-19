class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      
   int num=0;
    
        int i=31;
        while(n!=0) {
              
           int x = n&1;       
            int y = x<<i;     
            i--;                    
            num = num|y;               
            n = n>>1;               
        }
        return num;   
    }
};
