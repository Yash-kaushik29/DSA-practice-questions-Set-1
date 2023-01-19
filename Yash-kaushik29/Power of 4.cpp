class Solution {
public:
    bool isPowerOfFour(int num) {
     
          return num > 0 and !(num & (num - 1)) and (num & 0x55555555);
        
    }
};
