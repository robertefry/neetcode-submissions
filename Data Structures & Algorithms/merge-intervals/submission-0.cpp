
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.empty()) {
            return {};
        }

        sort(intervals.begin(), intervals.end());

        auto result = vector<vector<int>>{};
        result.reserve(intervals.size());
        result.push_back(intervals[0]);

        for (size_t i = 1; i < intervals.size(); ++i)
        {
            if (result.back()[0] <= intervals[i][0] && intervals[i][0] <= result.back()[1]) {
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
