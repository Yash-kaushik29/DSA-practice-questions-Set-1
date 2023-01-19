class Solution{
    public:
    vector<pair<int,int>> allPairs(int a[], int b[], int n, int m, int x)
    {
         vector<pair<int,int>> ans;
         sort(a,a+n);
         sort(b,b+m);
         unordered_set<int> s;
         for(int i=0;i<m;i++){
             s.insert(b[i]);
         }
         for(int i=0;i<n;i++){
             int val=x-a[i];
             if(s.find(val)!=s.end()){
                 ans.push_back({a[i],val});
                
             }
         }
         return ans;
    }
};
