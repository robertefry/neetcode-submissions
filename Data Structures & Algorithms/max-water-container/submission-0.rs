
impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32
    {
        let (mut i, mut j) = (0, heights.len()-1);
        let mut max_area = 0;

        while i < j {
            let area = (j-i) as i32 * std::cmp::min(heights[i],heights[j]);
            max_area = max_area.max(area);

            if heights[i] < heights[j] {
                i += 1;
            } else { // yuck
                j -= 1;
            }
        }

        max_area
    }
}
