
impl Solution
{
    const DELIM: char = '#';

    pub fn encode(lines: Vec<String>) -> String
    {
        let mut result = String::new();

        for line in lines {
            let length = line.len().to_string();
            result.push_str(&length);
            result.push(Self::DELIM);
            result.push_str(&line);
        }
        return result;
    }

    pub fn decode(string: String) -> Vec<String>
    {
        let mut string = string.as_str();
        let mut result = Vec::new();

        while !string.is_empty() {
            let Some((length,remainder)) = string.split_once(Self::DELIM)
            else {
                unreachable!("The string should contain the length delimiter.")
            };

            let Ok(length) = length.parse::<usize>()
            else {
                unreachable!("The length split should be parsable as a usize.")
            };

            let Some((line,remainder)) = remainder.split_at_checked(length)
            else {
                unreachable!("The remainder split should be at least {} characters long.", length)
            };

            result.push(line.to_string());
            string = remainder;
        }

        return result;
    }
}
