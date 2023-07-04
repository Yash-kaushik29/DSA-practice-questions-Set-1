#include <bits/stdc++.h> 
int findMinimumCost(string str) {
  
  int n = str.length();
  if(n & 1) return -1;

  stack<char> st;

  for(int i=0; i<n; i++) {
    if(str[i] == '{') {
      st.push(str[i]);
    } 
    else {
      if (!st.empty() && st.top() == '{') {
        st.pop();
      }
      else {
        st.push(str[i]);
      }
    }
  } 

  // Stack now contain only invalid expression

  int a=0, b=0;

  while(!st.empty()) {
    if(st.top() == '{') a++;
    else b++;

    st.pop();
  }

  return (a+1)/2 + (b+1)/2;    
}
