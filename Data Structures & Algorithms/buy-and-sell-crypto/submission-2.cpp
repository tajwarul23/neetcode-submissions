class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), left = 0;
       int mx = 0;

       for(int right = 1; right < n; right++){
        if(prices[right] - prices[left] > 0){
            mx = max(mx,prices[right] - prices[left] );
        }
        else left = right;
       }

       return mx;
    }
};