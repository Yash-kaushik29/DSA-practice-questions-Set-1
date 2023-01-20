class Solution {
private:
    bool checkEqual(int a[26], int b[26]) {

        for(int i=0 ; i<26 ; i++) {
            if(a[i]!=b[i])
            return 0;
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2) {
     
       int count1[26]={0};

       for(int i=0 ; i<s1.length() ; i++) {
           int index = s1[i] - 'a';
           count1[index]++;
       }

       int i=0;
       int windowSize = s1.length();
       int count2[26]={0};
       
       // checking for first window of size s1.length()

       while(i<windowSize && i<s2.length()) {
           int index=s2[i] - 'a';
           count2[index]++;
           i++;
       }

       if(checkEqual(count1,count2))  
       return 1;

      // checking for all possible windows
      
       while(i<s2.length()) {
           char newchar=s2[i];
           int index=newchar - 'a';
           count2[index]++;

           char oldchar=s2[i-windowSize];
           index=oldchar - 'a';
           count2[index]--;
           i++;
           
           if(checkEqual(count1,count2))  return 1;
       }

       return 0;

    }
};
