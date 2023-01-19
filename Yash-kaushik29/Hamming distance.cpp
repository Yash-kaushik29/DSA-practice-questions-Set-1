class Solution {
public:
    int hammingDistance(int x, int y) {
      int c=0;
        int temp=x^y;
        while(temp!=0)
        {
            temp=temp&(temp-1);
            c++;
        }
        return c;
    }
};
