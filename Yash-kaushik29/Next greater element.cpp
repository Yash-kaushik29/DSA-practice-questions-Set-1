class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
       vector<long long> v;

       

         long long x=-1;

         v.push_back(x);

         stack<long long>s;

         s.push(arr[n-1]);

         for(long long i=n-2;i>=0;i--){

             while(s.empty() == false && s.top()<arr[i]){

                 s.pop();

             }

            if(s.empty()==true){

                 v.push_back(-1);

             }

             else{

                 v.push_back(s.top());

             

             }

             s.push(arr[i]);

         }

         reverse(v.begin(),v.end());

        return v; 

    
    }
};
