class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> s1;
        vector<char> s2;
        
        for(int i=0 ; i<n ; i++) {
            
            if((str[i]>='a') && (str[i]<='z'))
            s1.push_back(str[i]);
            
            else
            s2.push_back(str[i]);
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        int m=0,k=0;
        
        for(int i=0 ; i<n ; i++) {
            if((str[i]>='a') && (str[i]<='z')) {
                str[i]=s1[m];
                m++;
            }
            
            else {
                str[i]=s2[k];
                k++;
            }
        }
        
        return str;
    }
};
