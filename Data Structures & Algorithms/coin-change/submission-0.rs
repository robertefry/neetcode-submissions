
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32
    {
        use std::collections::*;
        // count(i,target) := min{ count(i+1,target)?, 1 + count(i,target-coins[i])? }
        // count(_,0) := 0
        // count(i,_) := None  ForAll(i>=n)

        fn count(memo: &mut HashMap<(usize,i32),Option<i32>>,
            coins: &[i32], i: usize, target: i32) -> Option<i32>
        {
            if i >= coins.len() { return None; }
            if target == 0 { return Some(0); }

            if let Some(&result) = memo.get(&(i,target)) {
                return result;
            }
            let result = {
                let take_coin = if target < coins[i] { None } else {
                    count(memo, coins, i, target - coins[i]).map(|x| x + 1)
                };
                let skip_coin = if i >= coins.len()-1 { None } else {
                    count(memo, coins, i+1, target)
                };

                match (take_coin,skip_coin) {
                    (Some(a),Some(b)) => Some(std::cmp::min(a,b)),
                    (Some(x),None) | (None,Some(x)) => Some(x),
                    (None,None) => None,
                }
            };
            memo.insert((i,target), result);
            result
        }
        count(&mut HashMap::new(), &coins, 0, amount).unwrap_or(-1)
    }
}
