class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
       unordered_map<int,int> m;
       vector<int> v;
         
       for(int i=0 ; i<n ; i++)
       {
           m[arr[i]]++;
       }
       
       for(auto it:m)
       {
           if(it.second > 1)
            v.push_back(it.first);
       }
       
       if(v.size()==0) 
       {
           v.push_back(-1);
       }
       
       sort(v.begin(),v.end());
       
       return v; 
       
    
     
     /*  vector<int> ans;
       for(int i=0;i<n;i++){
           int index = arr[i]%n; //Jo no. mil gya use index p le k jaega
           arr[index]+=n;
       }
       for(int i=0;i<n;i++){
           if(arr[i]/n>=2) ans.push_back(i);
       }
       if(ans.size()==0) return {-1};
       return ans; */
    }
};
