
impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32
    {
        let (mut i, mut j) = (0, nums.len()-1);

        while i < j
        {
            let k = (i+j) / 2;

            if nums[k] > nums[j] {
                i = k+1;
            } else {
                j = k;
            }
        }

        nums[i]
    }
}
