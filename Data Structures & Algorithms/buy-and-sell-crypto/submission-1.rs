
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32
    {
        let (mut l, mut r) = (0,0);
        let mut max_profit = 0;

        while r < prices.len()-1
        {
            r += 1;

            let profit = prices[r] - prices[l];
            if profit < 0 {
                l = r;
                continue;
            }

            max_profit = max_profit.max(profit);
        }

        max_profit
    }
}
