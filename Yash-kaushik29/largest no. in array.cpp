class Solution
{
public:
    int largest(vector<int> &arr, int n)
    {
        sort(arr.begin(),arr.end());
        
        return arr[n-1];
    }
};
