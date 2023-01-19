class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int a[26]={0};
        int num,ans;
        for(int i=0 ; i<str.length() ; i++) {
            
            if((str[i]>='a')&&(str[i]<='z'))
            num=str[i]-'a';
            
            else
            num=str[i]-'A';
            
            a[num]++;
        }
        
        int maxi=-1;
        for(int i=0 ; i<26 ; i++){
            
            if(a[i]>maxi) {
            maxi=a[i];
            ans=i;
            }
        }
        
        return 'a'+ ans;
    }

};
