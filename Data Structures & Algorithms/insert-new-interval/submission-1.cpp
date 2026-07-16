
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& new_interval)
    {
        // assumption: Forall(i){ intervals[i][0] < intervals[i][1] }
        // assumption: Forall(i,j){ i < j => intervals[i][1] < intervals[j][0] }

        auto result = vector<vector<int>>{};
        result.reserve(intervals.size() + 1);

        auto index = 0;

        // 1. Insert all non-overlapping intervals ending before new_interval.

        for (; index < intervals.size(); ++index)
        {
            if (intervals[index][1] >= new_interval[0]) {
                break;
            }
            result.push_back(intervals[index]);
        }

        // 2. Merge overlapping intervals and push.

        auto merge = new_interval;

        for (; index < intervals.size(); ++index)
        {
            if (merge[1] < intervals[index][0]) {
                break;
            }
            if (intervals[index][0] < merge[0]) {
                merge[0] = intervals[index][0];
            }
            if (intervals[index][1] > merge[1]) {
                merge[1] = intervals[index][1];
            }
        }
        result.push_back(merge);

        // 3. Insert all non-overlapping intervals starting after new_interval

        for (; index < intervals.size(); ++index) {
            result.push_back(intervals[index]);
        }

        return result;
    }
};
