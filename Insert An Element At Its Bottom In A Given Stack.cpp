#include <bits/stdc++.h> 
void insert(stack<int>& s, int x) {

    if(s.empty()) {
        s.push(x);
        return ;
    }

    int num = s.top();
    s.pop();
    insert(s,x);
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
     insert(myStack,x);

     return myStack;
}
