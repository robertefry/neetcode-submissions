
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int best_profit = 0;

        for (size_t i = 0, j = 1; j < prices.size(); ++j)
        {
            if (prices[j] < prices[i]) {
                i = j; // new lower-low found
                continue;
            }
            best_profit = max(best_profit, prices[j] - prices[i]);
        }
        return best_profit;
    }
};
