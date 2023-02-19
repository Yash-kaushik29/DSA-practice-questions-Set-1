class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int n = prices.size();

        if(n == 1)
          return profit;
        
        int i = 0;
        while(i < n-1) {

            // Find best time to buy the stock
            while((i < n-1) && prices[i] >= prices[i+1])
              i++;

            if(i == n-1)
              break;

            int buy = i;   
            i++;
            // Find best time to sell the stock
            while((i < n)  && prices[i] >= prices[i-1]) 
             i++;

            int sell = i-1;

            profit += prices[sell] - prices[buy];  
        }  

        return profit;
    }
};
