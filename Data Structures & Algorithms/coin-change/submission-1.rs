
impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32
    {
        use std::collections::*;
        // count[amount] := 1 + Min(i){ count[amount-coin[i]] }
        // ForAll(i){ count[coin[i]] := 1 }

        let coins: HashSet<_> = coins.into_iter()
            .filter(|&coin| coin <= amount)
            .collect();

        let n = amount as usize + 1;
        let mut counts = vec![None;n];

        for &coin in &coins {
            counts[coin as usize] = Some(1);
        }
        counts[0] = Some(0);

        for amount in 1..n {
            counts[amount] = coins.iter()
                .filter(|&coin| amount >= *coin as usize)
                .filter_map(|coin| counts[amount - *coin as usize])
                .map(|count| count + 1)
                .min();
        }
        return counts[amount as usize].unwrap_or(-1);
    }
}
