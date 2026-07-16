
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() <= 1) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        auto fast = 1; // takes from intervals and merges into slow
        auto slow = 0; // marks the end of the current merge set

        for (; fast < intervals.size(); ++fast)
        {
            if (intervals[fast][0] <= intervals[slow][1]) {
                intervals[slow][1] = std::max(intervals[slow][1], intervals[fast][1]);
                continue;
            }
            intervals[++slow] = intervals[fast];
        }

        intervals.resize(slow+1);
        return intervals;
    }
};
