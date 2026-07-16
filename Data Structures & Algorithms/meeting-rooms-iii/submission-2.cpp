
#include <cassert>

struct MeetingRoom {
    int id;
    int next_available_time;
    int use_count;

    template <typename Order>
    using Heap = priority_queue<MeetingRoom, vector<MeetingRoom>, Order>;

    struct ByID {
        bool operator()(MeetingRoom const& room_1, MeetingRoom const& room_2) {
            return room_1.id > room_2.id;
        }
    };
    using HeapByID = Heap<ByID>;

    struct ByAvailability {
        bool operator()(MeetingRoom const& room_1, MeetingRoom const& room_2) {
            return room_1.next_available_time > room_2.next_available_time;
        }
    };
    using HeapByAvailability = Heap<ByAvailability>;
};

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings)
    {
        // use a heap of available meeting rooms ordered by id, and occupied
        // meeting rooms ordered by next availability time. at each meeting
        // we reclassify meeting rooms at the start time as available or occupied
        // and use the next available meeting room according to allocation rules.

        assert(n > 0);

        // 1. sort the meetings by their start time.
        constexpr auto by_start = [](vector<int> const& meeting_1, vector<int> const& meeting_2) {
            return meeting_1[0] < meeting_2[0];
        };
        std::sort(meetings.begin(), meetings.end(), by_start);

        // 2. open n meeting rooms.
        auto rooms_available = MeetingRoom::HeapByID{};
        auto rooms_occupied  = MeetingRoom::HeapByAvailability{};
        int current_time = 0;

        auto const advance_time = [&](int duration)
        {
            current_time += duration;

            while (not rooms_occupied.empty())
            {
                auto const room = rooms_occupied.top();
                if (room.next_available_time > current_time) {
                    break;
                }

                rooms_occupied.pop();
                rooms_available.push(std::move(room));
            }
        };

        for (int id = 0; id < n; ++id) {
            rooms_available.push(MeetingRoom {
                .id = id,
                .next_available_time = 0,
                .use_count = 0,
            });
        }

        // 3. for each meeting, use the next allocated meeting room, delaying if necessary.
        for (auto meeting : meetings)
        {
            if (meeting[0] < current_time) {
                auto const delay = current_time - meeting[0];
                meeting[0] += delay;
                meeting[1] += delay;
            }
            if (meeting[0] > current_time) {
                advance_time(meeting[0] - current_time);
            }

            // if there's no available rooms, we'll need to delay the meeting.
            if (rooms_available.empty())
            {
                auto const delay = rooms_occupied.top().next_available_time - meeting[0];
                meeting[0] += delay;
                meeting[1] += delay;

                advance_time(delay);
            }
            // TODO: debug_assert(not rooms_available.empty());

            auto room = rooms_available.top();
            rooms_available.pop();

            room.next_available_time = meeting[1];
            room.use_count += 1;

            rooms_occupied.push(std::move(room));
        }

        // 4. find the id of the most-used meeting room.
        auto best_room = rooms_occupied.top();
        rooms_occupied.pop();

        auto const drain_to_best_room = [&](auto& room_heap)
        {
            while (not room_heap.empty())
            {
                auto const room = room_heap.top();
                room_heap.pop();

                if (false
                    || room.use_count > best_room.use_count
                    || room.use_count == best_room.use_count && room.id < best_room.id
                ) {
                    best_room = room;
                    continue;
                }
            }
        };
        drain_to_best_room(rooms_available);
        drain_to_best_room(rooms_occupied);

        return best_room.id;
    }
};
