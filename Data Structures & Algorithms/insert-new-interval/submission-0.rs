
impl Solution {
    pub fn insert(intervals: Vec<Vec<i32>>, new_interval: Vec<i32>) -> Vec<Vec<i32>>
    {
        // assumption: intervals is sorted by (|vec| vec[0])

        // TODO: we should be able to do this inline without copying
        let mut index = 0;
        let mut result = Vec::with_capacity(intervals.len() + 1);

        // 1. push any interval before new_interval
        while index < intervals.len() && intervals[index][1] < new_interval[0] {
            result.push(intervals[index].clone());
            index += 1;
        }

        // 2. if all intervals are before new_interval, simply append new_interval.
        if index >= intervals.len() {
            result.push(new_interval);
            return result;
        }

        // 3. merge any overlapping intervals
        {
            let mut merge = new_interval;
            merge[0] = std::cmp::min(merge[0], intervals[index][0]);

            while index < intervals.len() && intervals[index][0] <= merge[1] {
                merge[1] = std::cmp::max(merge[1], intervals[index][1]);
                index += 1;
            }
            result.push(merge);
        }

        // 4. push any interval after new_interval
        while index < intervals.len() {
            result.push(intervals[index].clone());
            index += 1;
        }

        return result;
    }
}
