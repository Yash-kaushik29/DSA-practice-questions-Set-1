class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
    
        for(int i=0; i<x.length(); i++) {
        char ch = x[i];
        if(ch == '(' || ch == '[' || ch == '{') {
          st.push(ch);
        }
        else {
            if(!st.empty()) {
                char top = st.top();
                
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '[') ) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
       }
     
      if(st.empty())
        return true;
     
      else 
        return false;
    }

};
