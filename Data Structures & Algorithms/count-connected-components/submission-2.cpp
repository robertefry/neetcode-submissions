
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        auto graph = unordered_map<int,unordered_set<int>>{};

        for (auto const& edge : edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        auto unseen = unordered_set<int>{};

        for (int i = 0; i < n; ++i) {
            unseen.insert(i);
        }

        size_t islands = 0;

        while (not unseen.empty())
        {
            auto nodes = vector<int>{};
            nodes.push_back(*unseen.begin());

            auto visited = unordered_set<int>{};
            islands += 1;

            while (not nodes.empty())
            {
                auto node = nodes.back();
                nodes.pop_back();

                if (visited.contains(node)) {
                    continue;
                }
                unseen.erase(node);
                visited.insert(node);

                if (graph.contains(node))
                    for (auto connection : graph.at(node))
                {
                    nodes.push_back(connection);
                }
            }
        }

        return islands;
    }
};
