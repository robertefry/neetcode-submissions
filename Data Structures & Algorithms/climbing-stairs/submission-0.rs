
impl Solution {
    pub fn climb_stairs(n: i32) -> i32
    {
        use std::collections::*;

        fn climb(n: i32, cache: &mut HashMap<i32,i32>) -> i32
        {
            if n < 0 { return 0; }
            if n < 2 { return 1; }

            if let Some(&count) = cache.get(&n) {
                return count;
            }

            let count = climb(n-1, cache) + climb(n-2, cache);
            cache.insert(n, count);
            return count;
        }

        climb(n, &mut HashMap::new())
    }
}
