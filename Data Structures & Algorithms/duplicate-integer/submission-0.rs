
use std::collections::HashSet;

impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool
    {
        let mut hash_set = HashSet::new();

        for num in nums {
            if hash_set.contains(&num) {
                return true;
            }
            hash_set.insert(num);
        }
        return false;
    }
}
