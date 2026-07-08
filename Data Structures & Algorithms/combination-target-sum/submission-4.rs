
impl Solution {
    pub fn combination_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>>
    {
        fn combination_sum(nums: &[i32], i: usize, target: i32) -> Vec<Vec<i32>>
        {
            if i >= nums.len() || nums[i] > target {
                return if target == 0 { vec![vec![]] } else { Vec::new() }
            }

            let mut result = Vec::new();

            for taken in 0.. {
                if taken * nums[i] > target {
                    break;
                }

                let partials = combination_sum(nums, i+1, target - taken * nums[i]);

                for mut partial in partials {
                    partial.extend(std::iter::repeat_n(nums[i], taken as usize));
                    result.push(partial);
                }
            }

            return result;
        }
        nums.sort_unstable();
        combination_sum(&nums, 0, target)
    }
}
