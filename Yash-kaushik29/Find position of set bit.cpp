class Solution {
  public:
    int findPosition(int N) {
        // code here
        int pos=0;
        
        if(N==0)
        return -1;
        
        if(N & (N-1))
        return -1;
        
        while(N>0) {
            pos++;
            N = N>>1;
        }
        
        return pos;
    }
};
