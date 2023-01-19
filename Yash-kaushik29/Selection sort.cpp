class Solution
{
    public:
    int select(int arr[], int i, int n)
    {
        // code here such that selectionSort() sorts arr[]
        int min=i;
        int temp;
        int j;
        
        for(j=i+1 ; j<n; j++)  {
            
            if(arr[j]<arr[min]) 
                min=j;
            
        }
        
        swap(arr[i],arr[min]); 
        
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       for(int i=0 ; i<n-1 ; i++) {  
           
           
           select(arr,i,n);
       /*   int min=i;
           for(int j=i+1; j<n ; j++)  {
               
               if(arr[j]<arr[min])
                min=j;
           }
           swap(arr[min],arr[i]);   */
       }
    }
};
