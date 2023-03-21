class Solution{
public:	
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    // code here
	    vector<pair<int, int> > v;
	    
	    for(int i=0; i<n; i++) {
	        v.push_back({arr[i],i});
	    }
	    
	    sort(v.begin(),v.end());
	    
	    for(int i=0; i<n; i++) {
	        arr[v[i].second]=i;
	    }
	   
	}

};
