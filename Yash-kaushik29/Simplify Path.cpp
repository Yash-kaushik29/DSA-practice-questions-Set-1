// Appproach 1

class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> st;
        string res;
        
        for(int i = 0;  i<path.size(); ++i)
        {
            if(path[i] == '/')    
                continue;
            string temp;
			// iterate till we doesn't traverse the whole string and doesn't encounter the last /
            while(i < path.size() && path[i] != '/')
            {
				// add path to temp string
                temp += path[i];
                ++i;
            }
            if(temp == ".")
                continue;
			// pop the top element from stack if exists
            else if(temp == "..")
            {
                if(!st.empty())
                    st.pop();
            }
            else
			// push the directory file name to stack
                st.push(temp);
        }
        
		// adding all the stack elements to res
        while(!st.empty())
        {
            res = "/" + st.top() + res;
            st.pop();
        }
        
		// if no directory or file is present
        if(res.size() == 0)
            return "/";
        
        return res;
    }
};


// Approach 2

class Solution {
public:
    string simplifyPath(string path) {
      
      int n = path.size();
      //converting '/' to ' ' for stringstream
      for(int i=0; i<n; ++i) {
        if(path[i]=='/') path[i] = ' '; 
      }

      vector<string>v;
      stringstream s(path);
      string word;

      while(s>>word) 
      {
        if(word=="..")
        {
          // if encountered a ".." no point in popping as vector is empty
          if(v.empty()) continue;
         // if not then pop
          else v.pop_back();
        }
        else if(word==".") continue;
        else v.push_back(word);
      }

      string res = "/";

      for(auto it : v) {
        res+= it + "/";
      }
      //string should not end with '/' so pop
      if(res.back()=='/' && res.size() > 1)res.pop_back();
      return res;
    }
};
