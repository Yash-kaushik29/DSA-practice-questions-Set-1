class Solution {
  public:
    int findPosition(int N) {
        // code here
        if(N & N-1 || N==0) return -1;
        
        int pos=0;
        
        while(N) {
            pos++;
            N=N>>1;
        }
        
        return pos;
    }
};
