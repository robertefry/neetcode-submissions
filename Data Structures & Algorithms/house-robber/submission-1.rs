
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32
    {
        use std::collections::*;

        fn rob(nums: &[i32], i: usize, cache: &mut HashMap<usize,i32>) -> i32
        {
            if i >= nums.len() {
                return 0;
            }
            if i+1 >= nums.len() {
                return nums[i];
            }

            if let Some(&v) = cache.get(&i) {
                return v;
            }

            let v = std::cmp::max(
                nums[i+0] + rob(nums, i+2, cache),
                nums[i+1] + rob(nums, i+3, cache),
            );
            cache.insert(i, v);
            return v;
        }
        rob(&nums, 0, &mut HashMap::new())
    }
}
