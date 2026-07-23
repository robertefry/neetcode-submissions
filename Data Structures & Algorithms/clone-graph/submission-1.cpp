
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        constexpr auto has_neighbor = [](Node const* node, Node const* neighbor) {
            // assumption: node != nullptr
            auto const found = std::find(node->neighbors.begin(), node->neighbors.end(), neighbor);
            return found != node->neighbors.end();
        };

        auto map = std::unordered_map<Node*,Node*>{}; // (old->new)
        auto stack = std::stack<tuple<Node*,Node*>>{}; // (parent->old)

        // TODO: unroll the first iteration, though compiler might do this for us.
        stack.push({nullptr,node});

        while (not stack.empty())
        {
            auto const [parent, node] = stack.top();
            stack.pop();

            // invariant: node != nullptr
            // invariant: parent != nullptr => map.contains(parent)

            bool const copied = map.contains(node);

            // copy the node if necessary
            if (not copied) {
                auto new_node = new Node{node->val};
                new_node->neighbors.reserve(node->neighbors.size());
                map.emplace(node, std::move(new_node));
            }

            // copy the connection from the parent if necessary
            if (parent != nullptr && not has_neighbor(map[parent], map[node])) {
                map[parent]->neighbors.push_back(map[node]);
            }

            // process the node's neighbors and connections, only if we've not already done so
            if (not copied)
                for (auto neighbor : node->neighbors)
            {
                stack.push({node, neighbor});
            }
        }

        return map[node];
    }
};
