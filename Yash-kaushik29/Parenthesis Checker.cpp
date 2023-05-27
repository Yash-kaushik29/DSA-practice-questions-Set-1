class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        
        for(auto ch: x) {
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                if(!st.empty()) {
                    char top = st.top();
                    if((ch==')' && top=='(') || (ch=='}' && top=='{') || (ch==']' && top=='[')) {
                        st.pop();
                    }
                    else 
                        return false;
                }
                else {
                    return false;
                }
            }
        }
        
        return st.empty() ? true : false;
    }
};
