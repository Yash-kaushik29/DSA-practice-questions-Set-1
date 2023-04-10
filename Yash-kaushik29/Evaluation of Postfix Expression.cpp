class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int Operation(int x, int y, char c)
    {
        if(c == '+')
            return x+y;
        else if(c == '-')
            return x-y;
        else if(c == '*')
            return x*y;
        else if(c == '/')
            return x/y;
    }
    
    int evaluatePostfix(string S)
    {
        stack<int> st;
        
        for(int i=0; i<S.length(); i++) {
            char ch = S[i];
            
            if((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                
                int res = Operation(num2, num1, ch);
                st.push(res);
            }
            else {
                st.push(S[i]-'0');
            }
        }
        
        return st.top();
    }
};
