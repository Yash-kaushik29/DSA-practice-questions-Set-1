
class Solution {
  public:
    int minOperation(string s) {
        // code here
        if(s.size()<=3) 
        return s.size();
        
        int ans=s.size();
        string str="";
        
        for(int i=0 ; i<s.size() ; i++) {
            str=str+s[i];
            string temp= s.substr(i+1,str.size());
            
            if(temp==str) {
                // counting the number of operations if a substring is repeated
                int operations=str.size() + 1 + (s.size()-(str.size()*2));
                ans=min(ans,operations);
            }
        }
        
        return ans;
    }
};
