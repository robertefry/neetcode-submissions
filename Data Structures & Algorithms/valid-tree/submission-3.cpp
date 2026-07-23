
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
        auto nodes = stack<int>{};

        nodes.push(0);

        while (not nodes.empty())
        {
            auto const node = nodes.top();
            nodes.pop();

            if (visited.contains(node)) {
                continue;
            }
            visited.insert(node);

            if (visited.size() > n) {
                return false;
            }

            for (auto connection : connections.at(node)) {
                nodes.push(connection);
            }
        }

        return visited.size() == n;
    }
};
