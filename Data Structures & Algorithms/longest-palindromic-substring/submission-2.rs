
impl Solution {
    pub fn longest_palindrome(s: String) -> String
    {
        use std::cmp::*;

        let n = s.len();
        let chars: Vec<char> = s.chars().collect();
        let mut best = None;

        for i in 0..n
        {
            let odd = (0..)
                .take_while(|&j| j < n.saturating_sub(i).min(i+1))
                .take_while(|&j| chars[i-j] == chars[i+j])
                .last()
                .map(|j| (i-j,i+j));
            let eve = (0..)
                .take_while(|&j| j < n.saturating_sub(i+1).min(i+1))
                .take_while(|&j| chars[i-j] == chars[i+j+1])
                .last()
                .map(|j| (i-j,i+j+1));

            best = [best,odd,eve].into_iter()
                .flatten()
                .max_by_key(|(l,r)| r-l);
        }
        best.map(|(l,r)| &s[l..=r]).unwrap_or("").to_string()
    }
}
