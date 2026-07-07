
impl Solution {
    pub fn is_palindrome(s: String) -> bool
    {
        let chrs: Vec<_> = s.chars()
            .filter(|c| c.is_alphanumeric())
            .map(|c| c.to_ascii_lowercase())
            .collect();
        let n = chrs.len();

        (0..(n>>1)).all(|i| chrs[i] == chrs[n-i-1])
    }
}
