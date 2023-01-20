class Solution
{
  public:
  int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      int n=Edge.size();
      int a[n]={0};
      int ans=0;
      int index=0;
      
      for(int i=0 ;i<n ; i++) {
          if(Edge[i]==-1) {
          continue;
          }
          a[Edge[i]]+=i;
          if(a[Edge[i]]>ans) {
              ans=a[Edge[i]];
              index=Edge[i];
          }
          else if(a[Edge[i]]==ans && Edge[i]>index) {
              index=Edge[i];
          }
        }
        return index;
  }
};
