// Normal approach

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Initialization some neccessary variables
        vector<int>v;
        
        // store the array in the new array
        for(auto num:nums1)   // O(n1)
            v.push_back(num);
        
        for(auto num:nums2)  // O(n2)
            v.push_back(num);
        
        // Sort the array to find the median
        sort(v.begin(),v.end());  // O(nlogn)
        
        // Find the median and Return it
        int n=v.size();  // O(n)
        
        return n%2?v[n/2]:(v[n/2-1]+v[n/2])/2.0;
    }
};

// Optimized solution

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) 
          return findMedianSortedArrays(nums2, nums1);

        int n1=nums1.size();
        int n2=nums2.size();
        int low=0, high=n1;

        while(low <= high) {
            int cut1 = (low+high)/2;
            int cut2 = (n1+n2+1) / 2 - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2-1];

            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1) {
                if((n1+n2) % 2 == 0) {
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
                else {
                    return max(left1, left2);
                }
            }
            else if(left1 > right2) {
                high = cut1-1;
            }
            else {
                low = cut1+1;
            }
        }
        return 0.0; 
    }
