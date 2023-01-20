class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1.0;
        long long pow=n;

        if(pow<0) {
            pow=-1*pow;
        }

        while(pow>0) {
            if(pow % 2) {
                ans*=x;
                pow--;
            }
            else {
                x*=x;
                pow/=2;;
            }
        }
        if(n<0) {
            ans= 1.0/ans;
        }

        return ans;
    }
};
