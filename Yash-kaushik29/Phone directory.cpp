class Solution{
public:
    class TrieNode{
        
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        
        TrieNode(char c){
            data = c;
            for(int i=0; i<26; i++){
                children[i] = nullptr;
            }
            isTerminal = false;
        }

    };
    
    class trie{
        
        public:
        TrieNode* root;
        
        trie(){
            root = new TrieNode('\0');
        }
        
        void insertUtil(TrieNode* root, string word){
            //base case
            if(word.size() == 0){
                root -> isTerminal = true;
                return;
            }
            int index = word[0] - 'a';
            TrieNode* child;
            if(root -> children[index] == NULL){
                child = new TrieNode(word[index]);
                root -> children[index] = child;
            } else {
                child = root -> children[index];
            }
            
            insertUtil(child, word.substr(1));
        }
        
        void insertWord(string word){
            insertUtil(root, word);
        }
        
        void printDirect(vector<string> &temp, TrieNode* curr, string prefix){
            if(curr -> isTerminal){
                temp.push_back(prefix);
            }
            
            for(char c='a' ; c<='z'; c++){
                
                TrieNode* next = curr -> children[c - 'a'];
                
                if(next != NULL){
                    prefix += c;
                    printDirect(temp, next, prefix);
                    prefix.pop_back();
                }
            }
        }
        
        void getDirect(string s, vector<vector<string>> &ans){
            
            string prefix = "";
            TrieNode* prev = root;
            int i;
            for(i=0; i<s.size(); i++){
                char last = s[i];
                prefix += last;
                
                TrieNode* curr = prev -> children[last - 'a'];
                if(curr == NULL){
                    break;
                }
                
                vector<string> temp;
                printDirect(temp, curr, prefix);
                ans.push_back(temp);
                prev = curr;
            }
            if( i < s.size()){
                while( i< s.size()){
                    ans.push_back({"0"});
                    i++;
                }
            }
        }
        
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>> ans;
        trie* t = new trie();
        for(int i=0; i<n; i++){
            t -> insertWord(contact[i]);
        }
        
        t -> getDirect(s, ans);
        return ans;
    }
};
