class Solution {
public:
    char getMaxCharacter(vector<int> count) {
        int maxi = INT_MIN;
        char ch;
        
        for(int i=0; i<26; i++) {
            if(count[i] > maxi) {
                maxi = count[i];
                ch = i + 'a';
            }
        }
        return ch;
    }

    string reorganizeString(string s) {
        int n = s.length();
        if(n==0) return "";
        
        vector<int> count(26,0);
        
        for(auto ch: s) {
            count[ch-'a']++;
        }
        
        char max_ch = getMaxCharacter(count);
        int maxCount = count[max_ch-'a'];
        
        // if max char freq > n+1/2 , result not possible
        if(maxCount > (n+1)/2) return "";
        
        int idx = 0;
        string res(n, ' ');
        
        // placing the max freq char at alternating positions first
        while(maxCount) {
            res[idx] = max_ch;
            idx+=2;
            maxCount--;
        }
        
        count[max_ch-'a'] = 0;
        
        for(int i=0; i<26; i++) {
            while(count[i]) {
                idx = (idx >= n) ? 1 : idx;
                res[idx] = 'a' + i;
                idx+=2;
                count[i]--;
            }
        }
        
        return res;
    }
};
