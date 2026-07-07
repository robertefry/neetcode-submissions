
impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32
    {
        let (mut i, mut j) = (0, nums.len()-1);

        while j-i > 1
        {
            let k = (i+j) / 2;

            if nums[k] > nums[j] {
                i = k;
            } else {
                j = k;
            }
        }

        std::cmp::min(nums[i],nums[j])
    }
}
