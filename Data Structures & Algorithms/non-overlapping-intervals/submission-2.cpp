
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end());

        auto i = 0;
        auto j = 1;
        auto removals = 0;

        while (j < intervals.size())
        {
            if (intervals[i][1] <= intervals[j][0]) {
                i = j;
                j += 1;
                continue;
            }

            if (intervals[i][1] > intervals[j][1]) {
                i = j;
            }
            j += 1;
            removals += 1;
        }
        return removals;
    }
};
