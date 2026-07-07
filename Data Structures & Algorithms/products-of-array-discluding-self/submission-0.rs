
impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32>
    {
        let n = nums.len();
        let mut prefixes = vec![1;n];
        let mut suffixes = vec![1;n];

        for i in 1..n {
            let j = n-i-1;
            prefixes[i] = prefixes[i-1] * nums[i-1];
            suffixes[j] = suffixes[j+1] * nums[j+1];
        }

        (0..n).map(|i| prefixes[i] * suffixes[i]).collect()
    }
}
