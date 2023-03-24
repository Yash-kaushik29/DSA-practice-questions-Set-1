class Solution {
public:
        int divide(int dividend, int divisor) {
      
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        if(dividend == INT_MIN and divisor == 1) return INT_MIN;

        long long dd=abs(dividend);
        long long dv=abs(divisor);

        bool sign=(dividend >=0) == (divisor>=0) ? true: false;
        int result=0;

        while(dv <= dd) {
            int count=1;
            long long sum=dv;

            while(sum <= dd-sum) {
                sum*=2;
                count*=2;
            }
            result+=count;
            dd-=sum;
        }

        return sign ? result: -result;
    }
};
