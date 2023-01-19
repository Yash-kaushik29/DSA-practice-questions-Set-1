class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int a[], int n)
    {
        // Your code here 
        for(int i=1 ; i<n ; i++)  {
            
            for(int j=0 ; j<n-i ; j++)  {
                
                if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
            }
        }
        
    }
};
