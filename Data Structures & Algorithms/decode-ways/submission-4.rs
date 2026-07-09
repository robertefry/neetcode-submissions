
impl Solution {
    pub fn num_decodings(s: String) -> i32
    {
        fn num_unit_encodings(chars: &[char]) -> i32 {
            if match chars {
                ['1'..='9'] => true,
                ['1', '0'..='9'] => true,
                ['2', '0'..='6'] => true,
                _ => false,
            } { 1 } else { 0 }
        }

        let n = s.len();
        let chars: Vec<_> = s.chars().collect();

        let mut counts = vec![0;n];
        if n >= 1 {
            counts[n-1] += num_unit_encodings(&chars[n-1..]);
        }
        if n >= 2 {
            counts[n-2] += num_unit_encodings(&chars[n-2..]);
            counts[n-2] += num_unit_encodings(&chars[n-2..n-1]) * counts[n-1];
        }

        for i in (0..n.saturating_sub(2)).rev() {
            counts[i] += num_unit_encodings(&chars[i..i+1]) * counts[i+1];
            counts[i] += num_unit_encodings(&chars[i..i+2]) * counts[i+2];
        }
        counts[0]
    }
}
