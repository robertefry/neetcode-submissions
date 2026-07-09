
impl Solution {
    pub fn rob(mut nums: Vec<i32>) -> i32
    {
        for i in 0..nums.len()
        {
            nums[i] = std::cmp::max(
                if i < 1 {0} else { nums[i-1] },
                if i < 2 {0} else { nums[i-2] } + nums[i],
            );
        }
        return nums.pop().unwrap_or(0);
    }
}
