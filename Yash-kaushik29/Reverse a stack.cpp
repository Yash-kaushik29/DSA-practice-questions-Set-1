class Solution{
public:
    void insertAtBottom(stack<int> &St, int num) {
        
        // base case
        if(St.empty()) {
            St.push(num);
            return ;
        }
        
        int element = St.top();
        St.pop();
        insertAtBottom(St,num);
        
        St.push(element);
    }

    void Reverse(stack<int> &St){
       
       // base case
       if(St.empty())
       return ;
       
       int num = St.top();
       St.pop();
       
       Reverse(St);
       
       insertAtBottom(St,num);
    }
};
