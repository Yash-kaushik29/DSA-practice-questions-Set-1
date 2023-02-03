class Solution {
public:
    int getSum(int a, int b) {
        
        int sum = 0, carry = 0; // 'carry' represents our carryarry bit
        int x = 0, y = 0;
        for (int i=0; i<32; i++) {
            x = 1 & a; a = a >> 1; 
            y = 1 & b; b = b >> 1;
            sum = sum | (((x ^ y) ^ carry) << i);
            carry = (x&y | y&carry | carry&x);
        }
        return sum;
    }
};
