
#include <ranges>

class CourseGraph final
{
    unordered_map<int,vector<int>> m_Graph {};
    unordered_set<int> mutable m_Finishable {};

public:

    explicit CourseGraph(vector<vector<int>> const& prerequisites)
    {
        // assumption: Forall(i){ prerequisites[i].size() == 2 }

        for (auto const& prerequisite : prerequisites) {
            m_Graph[prerequisite[0]].push_back(prerequisite[1]);
        }
    }

    [[nodiscard]] bool finishable(int course) const
    {
        auto visited = unordered_set<int>{};

        return [&](this auto&& self, int course) -> bool
        {
            if (m_Finishable.contains(course)) {
                return true;
            }

            if (visited.contains(course)) {
                return false; // cycle detected
            }
            visited.insert(course);

            if (not m_Graph.contains(course) || std::all_of(
                m_Graph.at(course).begin(),
                m_Graph.at(course).end(),
                [&](auto prerequisite) { return self(prerequisite); }
            )) {
                m_Finishable.insert(course);
                return true;
            }
            return false;
        }
        (course);
    }

};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        auto const graph = CourseGraph{prerequisites};

        return std::ranges::all_of(std::ranges::views::iota(0,numCourses), [&](auto course) {
            return graph.finishable(course);
        });
    }
};
