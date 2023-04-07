class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           int maxlen=0, len=0, product=1;
           
           for(int i=0; i<n; i++) {
               
               // if element is zero, reset len to 0 and product to 1 (new subarray)
               if(arr[i] == 0) {
                   len=0;
                   product=1;
                   continue;
               }
               
               if(arr[i] < 0) product*=-1;
               len++;
               
               // update length only when product is positive
               if(product > 0) maxlen = max(maxlen, len);
           }
           
           len=0; product=1;
           
           for(int i=n-1; i>=0; i--) {
               
               if(arr[i] == 0) {
                   len=0;
                   product=1;
                   continue;
               }
               
               if(arr[i] < 0) product*=-1;
               len++;
               
               if(product > 0) maxlen = max(maxlen, len);
           }
           
           return maxlen;
        }
};
