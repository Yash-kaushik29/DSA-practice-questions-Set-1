class Solution {
public:
        int divide(int dividend, int divisor) {
      
        int  sum=(long long)dividend/(long long)divisor;
        
        bool neg=false;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)){
            neg = true;
        }


        if(sum==INT_MIN && neg==false ){
            
                return INT_MAX;
            }
        else if(sum==INT_MAX && neg==true){
                return INT_MIN;
            }
        
        return sum;
        
    }
};
