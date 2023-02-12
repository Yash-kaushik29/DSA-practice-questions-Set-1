// Approach 1 : Using 2 stacks

int longestValidParentheses(string s) {
       stack<char> ch;
        stack<int> index;
        int ans = 0;
        index.push(-1);
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] =='(') {
                ch.push(s[i]);
                index.push(i);
            }
            else  {
                if(!ch.empty() && ch.top()=='(') {
                    ch.pop();
                    index.pop();
                    ans = max(ans,i-index.top());
                }
                else{
                    index.push(i);                    
                }
            }
        }
        return ans;



// Approach 2 : Constant space 

int longestValidParentheses(string s) {
       int left = 0, right = 0, ans= 0 ;
       int n = s.length();

       for(int i=0; i<n; i++) {
           if(s[i] == '(') {
               ++left;
           }
           else{
               ++right;
           }
           if(right == left)
           ans = max(ans,2*right);

           else if(right > left)
           left = right = 0;
       } 

       left = 0;
       right = 0;
       for(int i=n-1; i>=0; i--) {
           if(s[i] == '(') {
               ++left;
           }
           else{
               ++right;
           }
           if(right == left)
           ans = max(ans,2*right);

           else if(left > right)
           left = right = 0;
       }
       return ans; 
    }
