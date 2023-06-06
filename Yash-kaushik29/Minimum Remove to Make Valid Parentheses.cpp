class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int brackets=0, n=s.length();
        string res;

        for(int i=0; i<n; i++){
            if(s[i]=='(') brackets++;
            else if(s[i]==')'){
                if(brackets==0)s[i]='$';
                else brackets--;
            }
        }

        brackets=0;

        for(int i=n-1; i>=0; i--){
            if(s[i]==')')brackets++;
            else if(s[i]=='('){
                if(brackets==0) s[i]='$';
                else brackets--;
            }
        }
        for(int i=0; i<s.length(); i++)
            if(s[i]!='$')res+=s[i];
        return res;

    }
};
