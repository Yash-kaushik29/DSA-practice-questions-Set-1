class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        
        int i=0, j=0;
        int n=pushed.size();
        
        while(i < n) {
            while(j < n && (st.empty() || st.top() != popped[i])) {
                st.push(pushed[j]);
                j++;
            }
            
            if(!st.empty() && st.top() == popped[i]) {
                st.pop();
                i++;
            }
            
            else
              return false;
        }
        
        return true;
    }
};
