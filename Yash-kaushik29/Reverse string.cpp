// Normal approach

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int st=0;
        int e=s.size()-1;

        while(st<e) {
            swap(s[st++],s[e--]);
        }
    }
};

// Using recursion

class Solution {
public:
    void reverse(vector<char>& ans, int i , int j) {

        // base case
        if(i>j)
        return;

        swap(ans[i],ans[j]);
        //recursive call
        i++;
        j--;

        return reverse(ans,i,j);

    }
    
    vector<char> reverseString(vector<char>& v) {
        
        int s=0;
        int e=v.size()-1;

        reverse(v,s,e);
        return v;
  
    }
};
