class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int,int> m;
        vector<int> v;
        
        for(int i=0 ; i<arr.size() ; i++)
        {
            m[arr[i]]++;
        }
        
        for(auto it : m)
        {
            v.push_back(it.second);
        }
        
        sort(v.begin(),v.end());
        
        for(int j=0 ; j<v.size()-1 ; j++)
        {
            if(v[j]==v[j+1])
                return false;
        }

          return true;
    }
};
