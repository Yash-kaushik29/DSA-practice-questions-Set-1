void insert(stack<int> &s, int num) {
    
    if(s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return ;
        
    }
    
    int element = s.top();
    s.pop();
    
    insert(s,num);
    s.push(element);
    
}

void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
   return ;
   
   int num = s.top();
   s.pop();
   
   sort();
   insert(s,num);
}
