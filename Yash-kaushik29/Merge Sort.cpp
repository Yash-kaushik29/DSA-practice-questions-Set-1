class Solution {
public:
    void merge(vector<int>& arr, int s, int e) {
    
    int mid=s+(e-s)/2;
    int l1=mid-s+1;
    int l2=e-mid;

    // creating copy
    int *first=new int[l1];
    int *second=new int[l2];

    int k=s;
    for(int i=0; i<l1; i++)
      first[i]=arr[k++];

    for(int i=0; i<l2; i++)
      second[i]=arr[k++];

    int i1=0;
    int i2=0;
    int mainIndex=s;

    // merging of arrays
    while(i1<l1 && i2<l2) {
        if(first[i1]<second[i2]) {
            arr[mainIndex++]=first[i1++];
        }
        else {
            arr[mainIndex++]=second[i2++];
        }
    }

    while(i1<l1)
        arr[mainIndex++]=first[i1++];

    while(i2<l2)
        arr[mainIndex++]=second[i2++];    

}

void merge_sort(vector<int>& arr, int s, int e) {
    if(s>=e)
    return;

    int mid=s+(e-s)/2;
 
    // sorting left part
    merge_sort(arr,s,mid);

    // sorting right part
    merge_sort(arr,mid+1,e);

    merge(arr,s,e);
}
    
    vector<int> sortArray(vector<int>& arr) {
        merge_sort(arr,0,arr.size()-1);
        return arr;
    }
};
