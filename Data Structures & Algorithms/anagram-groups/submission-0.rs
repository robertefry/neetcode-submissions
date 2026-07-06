
use std::collections::*;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>>
    {
        let mut groups: HashMap<Vec<char>,Vec<String>> = HashMap::new();

        for string in strs {
            let mut key = string.chars().collect::<Vec<_>>();
            key.sort_unstable();
            groups.entry(key).or_default().push(string);
        }

        groups.into_values().collect()
    }
}
