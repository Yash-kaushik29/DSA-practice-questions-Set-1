class Solution
{
    class TrieNode{
      public:
        bool isEnd;
        TrieNode* children[26];
        int count;

        TrieNode(){
           isEnd=false;
           count=0;
           for(int i=0;i<26;i++) {
              children[i]=NULL;
           }
        }
    };
    
    public:
    void insert(TrieNode* root,string &word)
    {
        TrieNode* node=root;
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(!node->children[ind])node->children[ind]=new TrieNode();
            node->count++;
            node=node->children[ind];
        }
        node->count++;
        node->isEnd=true;
    }
    
    string search(TrieNode* root, string& word)
    {
        TrieNode* node=root;
        string res="";
        for(int i=0;i<word.size();i++)
        {
            int ind=word[i]-'a';
            if(node->children[ind]->count==1)
            {
                res+=word[i];
                break;
            }
            res+=word[i];
            node=node->children[ind];
        }
        return res;
    }
    
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        TrieNode* root=new TrieNode();
        vector<string>ans;
        
        for(int i=0;i<n;i++)
        {
            insert(root,arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(search(root,arr[i]));
        }
        return ans;
    }
    
};
