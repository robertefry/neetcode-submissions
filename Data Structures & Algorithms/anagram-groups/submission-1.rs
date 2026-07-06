
use std::collections::*;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>>
    {
        let mut groups: HashMap<String,Vec<String>> = HashMap::new();

        fn anagram_hash(string: &str) -> String {
            let mut chars: Vec<_> = string.chars().collect();
            chars.sort_unstable();
            chars.into_iter().collect()
        }

        for string in strs {
            let key = anagram_hash(&string);
            groups.entry(key).or_default().push(string);
        }

        groups.into_values().collect()
    }
}
