class Solution {
public:
    int romanToInt(string str) {
        vector<int> vals;
        int sum = 0;
        for(int i=0;i<str.length();i++)
        {
            char c = str[i];
            switch(c)
            {
                case 'I':
                    vals.push_back(1);
                    break;
                case 'V':
                    vals.push_back(5);
                    break;
                case 'X':
                    vals.push_back(10);
                    break;
                case 'L':
                    vals.push_back(50);
                    break;
                case 'C':
                    vals.push_back(100);
                    break;
                case 'D':
                    vals.push_back(500);
                    break;
                case 'M':
                    vals.push_back(1000);
                    break;
            }
        }
        
    
   sum += vals[0];
   for(int i=1;i<vals.size();i++)
   {
       if(vals[i-1] < vals[i])
       {
           sum+=(vals[i]-vals[i-1]);
           sum-=vals[i-1];
       }
       
       else
       {
           sum+=vals[i];
       }
   }
   return sum;
 }
};
