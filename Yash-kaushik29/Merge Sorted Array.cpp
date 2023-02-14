class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int first = m-1;
        int second = n-1;
        int index = m+n-1;
        while(first>-1 && second >-1)
        {

            if(nums1[first]>= nums2[second])
            {
                nums1[index] = nums1[first];
                index-- ;
                first-- ;

            }
            else
            {
                nums1[index] = nums2[second];
                index-- ;
                second-- ;
            }
        }
        while(first>-1)
        {
            nums1[index] = nums1[first];
            index-- ;
            first-- ;
        }
        while(second>-1)
        {
            nums1[index] = nums2[second];
            index-- ;
            second-- ;
        }
    }
};
