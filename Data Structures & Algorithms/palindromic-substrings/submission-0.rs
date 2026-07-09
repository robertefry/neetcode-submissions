
impl Solution {
    pub fn count_substrings(s: String) -> i32
    {
        use std::cmp::*;

        let n = s.len();
        let chars: Vec<char> = s.chars().collect();
        let mut count = 0;

        for i in 0..n
        {
            let odd = (0..)
                .take_while(|&j| j < n.saturating_sub(i).min(i+1))
                .take_while(|&j| chars[i-j] == chars[i+j])
                .fold(0, |count,_| count+1);
            let eve = (0..)
                .take_while(|&j| j < n.saturating_sub(i+1).min(i+1))
                .take_while(|&j| chars[i-j] == chars[i+j+1])
                .fold(0, |count,_| count+1);

            count += odd + eve;
        }
        count
    }
}
