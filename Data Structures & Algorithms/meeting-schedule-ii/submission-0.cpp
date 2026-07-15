
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals)
    {
        // we have a collection of meeting rooms and the next time they become
        // available. for each interval, if we don't have a meeting room available,
        // we'll need to open a new meeting room.

        // 1. sort the intervals by start time
        auto const sort_by_start = [](Interval const& interval_1, Interval const& interval_2) {
            return interval_1.start < interval_2.start;
        };
        std::sort(intervals.begin(), intervals.end(), sort_by_start);

        // 2. use a heap of meeting room availability times, the earliest available on top.
        auto meeting_rooms = priority_queue<int, vector<int>, greater<int>>{};

        // 3. open a new meeting room if the earliest available is after our start time.
        for (auto const& interval : intervals) {
            if (not meeting_rooms.empty() && meeting_rooms.top() <= interval.start) {
                meeting_rooms.pop();
            }
            meeting_rooms.push(interval.end);
        }

        // 4. return the number of meeting rooms used
        return meeting_rooms.size();
    }
};
