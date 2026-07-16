
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        // Use a heap of available meeting rooms ordered by id, and occupied
        // meeting rooms ordered by next availability time. At each meeting
        // we reclassify meeting rooms at the start time as available or
        // occupied, and use the next available meeting room.

        // TODO: debug_assert(n > 0);

        // 1. sort the meetings by their start time.
        std::sort(meetings.begin(), meetings.end());

        // 2. open the meeting rooms and keep track of their state.
        auto rooms_available = priority_queue<size_t, vector<size_t>, greater<>>{};
        auto rooms_occupied = priority_queue<tuple<int,size_t>, vector<tuple<int,size_t>>, greater<>>{};
        auto room_use_count = vector<size_t>(n,0);

        for (size_t id = 0; id < n; ++id) {
            rooms_available.push(id);
        }

        // 3. for each meeting, determine the state of each meeting room at the start,
        // and delay until a meeting room comes available.

        for (auto meeting : meetings)
        {
            // make available the meeting rooms finishing before this meeting starts
            while (not rooms_occupied.empty() && get<0>(rooms_occupied.top()) <= meeting[0]) {
                rooms_available.push(get<1>(rooms_occupied.top()));
                rooms_occupied.pop();
            }

            // delay this meeting until a meeting room comes available
            if (rooms_available.empty()) {
                meeting[1] += get<0>(rooms_occupied.top()) - meeting[0];
                rooms_available.push(get<1>(rooms_occupied.top()));
                rooms_occupied.pop();
            }

            // occupy the next available meeting room for this meeting
            auto const id = rooms_available.top();
            rooms_available.pop();
            rooms_occupied.push({meeting[1], id});
            room_use_count[id] += 1;
        }

        // 4. find the id of the most used room
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
