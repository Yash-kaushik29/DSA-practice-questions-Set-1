class Solution {
private:
    bool valid(char ch) {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        {
            return 1;
        }

        return 0;
    }

    char toLower(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') ) {
            return ch;
        }

        else {
            char temp = ch-'A'+'a';
            return temp;
        }
    }

    bool check(string a){
         int st=0;
         int e=a.length()-1;
     
      while(st<e) {

        if(a[st] != a[e])
         return false;

         else{
             st++;
             e--;
         }
   
    }

     return true;
    }


public:
    bool isPalindrome(string s) {

       string temp="";

       for(int i=0 ; i<s.length() ; i++)
       {
           if(valid(s[i])) {
               temp.push_back(s[i]);
           }
       }

       for(int j=0 ; j<temp.length() ; j++) {
          temp[j]= toLower(temp[j]);
       }

       return check(temp);
    }
};
