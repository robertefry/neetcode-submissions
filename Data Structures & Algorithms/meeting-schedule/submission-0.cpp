
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        auto const sort_by_start_time = [](Interval const& interval_1, Interval const& interval_2) {
            return interval_1.start < interval_2.start;
        };
        std::sort(intervals.begin(), intervals.end(), sort_by_start_time);

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i-1].end > intervals[i].start) {
                return false;
            }
        }
        return true;
    }
};
