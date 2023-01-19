class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
        int temp;
        
        for(int j=i ; j>0 ; j--)
        {
            
            if(arr[j]<arr[j-1])
            {
                temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
            
        }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i=1 ; i<n ; i++)  
        {
            
            insert(arr,i);
        }
    }
};
