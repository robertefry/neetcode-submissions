
impl Solution {
    pub fn rob(mut nums: Vec<i32>) -> i32
    {
        use std::cmp::max;

        if nums.len() == 0 { return 0; }
        if nums.len() == 1 { return nums[0]; }
        if nums.len() == 2 { return max(nums[0],nums[1]); }

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
