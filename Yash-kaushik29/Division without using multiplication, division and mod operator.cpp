class Solution
{
    public:
    long long divide(long long dividend, long long divisor) 
    {
        //code here
        long long quotient=0,temp=0;
        long long sign=((dividend<0) ^ (divisor<0)) ? -1:1;
        
        dividend=abs(dividend);
        divisor=abs(divisor);
        
        // while(dividend>=divisor) {
            
        //     dividend-=divisor;
        //     quotient++;
        // }
        
        for(int i=31;i>=0;i--){
            if(temp+(divisor<<i) <= dividend){
                temp += divisor<<i;
                quotient = (quotient)|(1<<i);
            }
        }
        
        return (sign*quotient);
    }
};
