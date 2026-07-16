
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        // Track available rooms as a min-heap of ids.
        // Track occupied rooms as a min-heap of {occupied_until,id}s
        //
        // For each meeting (strictly increasing in start time), we determine
        // which occupied rooms become available when the meeting starts, delay
        // the meeting until at least one room is available, then occupy this
        // room for the duration of the meeting.
        //

        // TODO: debug_assert(n > 0);

        // 1. Open the rooms.
        auto rooms_available = priority_queue<size_t, vector<size_t>, greater<>>{};
        auto rooms_occupied = priority_queue<tuple<int,size_t>, vector<tuple<int,size_t>>, greater<>>{};
        auto room_use_count = vector<size_t>(n,0);

        for (size_t id = 0; id < n; ++id) {
            rooms_available.push(id);
        }

        // 2. Sort the meetings by their start times.
        std::sort(meetings.begin(), meetings.end());

        // 3.
        for (auto meeting : meetings)
        {
            // Make available all rooms with meetings finishing before this meeting starts.
            while (not rooms_occupied.empty() && get<0>(rooms_occupied.top()) <= meeting[0]) {
                rooms_available.push(get<1>(rooms_occupied.top()));
                rooms_occupied.pop();
            }

            // Delay this meeting until at least one room comes available.
            if (rooms_available.empty()) {
                meeting[1] += get<0>(rooms_occupied.top()) - meeting[0];
                rooms_available.push(get<1>(rooms_occupied.top()));
                rooms_occupied.pop();
            }

            // Occupy the next available room for the duration of this meeting.
            auto const id = rooms_available.top();
            rooms_available.pop();
            rooms_occupied.push({meeting[1], id});
            room_use_count[id] += 1;
        }

        // 4. Find the id of the most occupied room.
        auto most_used_id = 0;
        auto most_used_count = room_use_count[0];

        for (size_t id = 1; id < room_use_count.size(); ++id) {
            if (most_used_count < room_use_count[id]) {
                most_used_id = id;
                most_used_count = room_use_count[id];
            }
        }
        return most_used_id;
    }
};
