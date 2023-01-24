class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	   vector<int> v(arr,arr+n);
	   sort(v.begin(),v.end());
	   unordered_map<int,int> m;
	   
	   for(int i=0 ; i<n ; i++)  {
	       m[v[i]]=i;
	   }
	   
	   for(int i=0 ; i<n ; i++)  {
	       arr[i]=m[arr[i]];
	   }
	   
	}

};
