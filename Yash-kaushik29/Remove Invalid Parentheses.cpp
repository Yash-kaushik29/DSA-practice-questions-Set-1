// Approach 1

class Solution {
    vector<string> ans;
    unordered_map<string, int> mp;
public:
    int findRemovals(string s) {
        stack<char> st;

        for(int i=0; i<s.length(); i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(st.size() && st.top()=='(') st.pop();
                else st.push(s[i]);
            }
        }
        return st.size();
    }

    void solve(string s, int minRemovals) {
        if(mp[s] > 0) return ;

        if(mp[s] == 0) mp[s]++;

        if(minRemovals < 0) return ;

        if(minRemovals == 0) {
            if(findRemovals(s) == 0) ans.push_back(s);
            return ;
        }

        for(int i=0; i<s.length(); i++) {
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right, minRemovals-1);
        }
        return ;
    }
  
    vector<string> removeInvalidParentheses(string s) {
        solve(s, findRemovals(s));
        return ans;
    }
};

// Approach 2

class Solution {
    public:
    bool solve(string s)
    {
        int x = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '(') x++;
            if(s[i] == ')') x--;

            if(x < 0) return false;
        }
        return x == 0;
    }

    vector<string> removeInvalidParentheses(string s) 
    {
        int n = s.size();
        vector<string>ans;
        unordered_map<string, int>mp, mp1;
        deque<string>q;

        bool flag = false;
        q.push_back(s);
        
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string curr = q.front();
                q.pop_front();


                if(solve(curr) && !mp[curr]) 
                {
                    ans.push_back(curr);
                    mp[curr]++;
                    flag = true;
                    continue;
                }
              
                for(int i=0; i<curr.size(); i++)
                {
                    if(curr[i] != ')' && curr[i] != '(') continue;
                    string temp = curr.substr(0, i) + curr.substr(i + 1);
                    if(!mp1[temp]) q.push_back(temp), mp1[temp]++;
                }
            }

            if(flag) break;
        }

        return ans;
    }
};
