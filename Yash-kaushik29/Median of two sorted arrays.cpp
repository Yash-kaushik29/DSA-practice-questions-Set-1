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
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);
        int s = 0, e = nums1.size();
        while(s<=e){
            int i1 = (s+e)>>1;
            int i2 = ((nums1.size()+nums2.size()+1)>>1)-i1;

            int max1 = (i1==0?INT_MIN:nums1[i1-1]);
            int max2 = (i2==0?INT_MIN:nums2[i2-1]);
            int min1 = (i1==nums1.size()?INT_MAX:nums1[i1]);
            int min2 = (i2==nums2.size()?INT_MAX:nums2[i2]);

            if(max1<=min2 && max2<=min1){
                if((nums1.size()+nums2.size())&1){
                    return (double)max(max1,max2);
                }else{
                    return ((double(max(max1,max2)+min(min1,min2))))/2;
                }
            }
            else if(max1>min2){
                e = i1-1;
            }
            else{
                s = i1+1;
            }
        }
        return -1.0;
    }
