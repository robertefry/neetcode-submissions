
impl Solution {
    pub fn rob(mut nums: Vec<i32>) -> i32
    {
        if nums.len() >= 2 {
            nums[1] = nums[1].max(nums[0]);
        }
        for i in 2..nums.len() {
            nums[i] = std::cmp::max( nums[i-1], nums[i-2] + nums[i]);
        }
        return nums.pop().unwrap_or(0);
    }
}
