
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.empty()) return n <= 1;
        if (edges.size() != n-1) return false;

        auto connections = unordered_map<int,unordered_set<int>>{};

        for (auto&& edge : std::move(edges)) {
            connections[edge[0]].insert(edge[1]);
            connections[edge[1]].insert(edge[0]);
        }

        auto visited = unordered_set<int>{};
        auto nodes = vector<tuple<int,int>>{};

        visited.insert(0);
        for (auto connection : connections.at(0)) {
            nodes.push_back({0, connection});
        }

        while (not nodes.empty())
        {
            auto const [parent, node] = nodes.back();
            nodes.pop_back();

            if (visited.contains(node)) {
                return false;
            }
            visited.insert(node);

            if (visited.size() > n) {
                return false;
            }

            for (auto connection : connections.at(node))
            {
                if (connection == parent) {
                    continue;
                }
                nodes.push_back({node, connection});
            }
        }

        return visited.size() == n;
    }
};
