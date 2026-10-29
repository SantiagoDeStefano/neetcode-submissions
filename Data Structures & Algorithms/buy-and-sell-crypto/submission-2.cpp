class Solution {
public:
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int left = 0;
    int right = 1;
    int maxProfit = 0;

    while(right < n) {
        if(prices[right] - prices[left] >= 0) {
            int profit = prices[right] - prices[left];
            maxProfit = max(maxProfit, profit);
            right++;
        }
        else {
            left = right;
            right++;
        }
    }
    return maxProfit;
}

};
