
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (edges.empty()) {
            return n <= 1;
        }

        auto connections = unordered_map<int,unordered_set<int>>{};

        for (auto&& edge : std::move(edges)) {
            connections[edge[0]].insert(edge[1]);
            connections[edge[1]].insert(edge[0]);
        }

        auto visited = unordered_set<int>{};
        auto nodes = stack<tuple<int,int>>{};

        visited.insert(0);
        for (auto connection : connections.at(0)) {
            nodes.push({0, connection});
        }

        while (not nodes.empty())
        {
            auto const [parent, node] = nodes.top();
            nodes.pop();

            if (visited.contains(node)) {
                return false; // cycle detected
            }
            visited.insert(node);

            for (auto connection : connections.at(node))
            {
                if (connection == parent) {
                    continue;
                }
                nodes.push({node, connection});
            }
        }

        return visited.size() == n;
    }
};
