// Method 1:- Normal approach

class Solution {
public:
    char findTheDifference(string s, string t) {
       int ans=0;
       char c;
       for(int i=0 ; i<t.length() ; i++) {
           int ch=t[i]-'a';
           ans+=ch;
       }

       for(int i=0 ; i<s.length() ; i++) {
           int ch=s[i]-'a';
           ans-=ch;
       }
       
       c=ans+'a';
       return c;
    }
};

// Method 2:- Using XOR (minimum runtime)

class Solution {
public:
    char findTheDifference(string s, string t) {
       int ans=0;
       char c;
       for(int i=0 ; i<t.length() ; i++) {
           int ch=t[i]-'a';
           ans^=ch;
       }

       for(int i=0 ; i<s.length() ; i++) {
           int ch=s[i]-'a';
           ans^=ch;
       }
       
       c=ans+'a';
       return c;
    }
};


// Method 3:- using Hash table

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        char ch;

        for(int i=0 ; i<s.length() ; i++) {
            mp[s[i]]++;
        }

        for(int i=0 ; i<t.length() ; i++) {
            mp[t[i]]++;
        }

        for(auto it:mp) {
            if(it.second&1) {
            ch=it.first;
            break;
            }
        }
        return ch;
    }
};
