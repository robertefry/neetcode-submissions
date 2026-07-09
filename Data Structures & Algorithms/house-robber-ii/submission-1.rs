
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32
    {
        use std::collections::*;

        fn rob(nums: &[i32], i: usize, max: usize, cache: &mut HashMap<usize,i32>) -> i32
        {
            if i >= max{
                return 0;
            }
            if i+1 >= max {
                return nums[i];
            }

            if let Some(&v) = cache.get(&i) {
                return v;
            }

            let v = std::cmp::max(
                nums[i+0] + rob(nums, i+2, max, cache),
                nums[i+1] + rob(nums, i+3, max, cache),
            );
            cache.insert(i, v);
            return v;
        }

        if nums.len() == 0 {
            return 0;
        }
        if nums.len() == 1 {
            return nums[0];
        }

        std::cmp::max(
            rob(&nums, 0, nums.len().saturating_sub(1), &mut HashMap::new()),
            rob(&nums, 1, nums.len().saturating_sub(0), &mut HashMap::new()),
        )
    }
}
