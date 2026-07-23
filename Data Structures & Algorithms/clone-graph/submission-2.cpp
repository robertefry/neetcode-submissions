
class Solution {
public:
    Node* cloneGraph(Node* node)
    {
        if (node == nullptr) {
            return nullptr;
        }

        auto copies = unordered_map<Node*,Node*>{}; // (old->new)
        auto neighbors = unordered_map<Node*,unordered_set<Node*>>{}; // (new->neighbors)

        auto stack = std::stack<tuple<Node*,Node*>>{}; // (parent->old)

        // TODO: unroll the first iteration, though compiler might do this for us.
        stack.push({nullptr,node});

        while (not stack.empty())
        {
            auto const [parent, node] = stack.top();
            stack.pop();

            // invariant: node != nullptr
            // invariant: parent != nullptr => copies.contains(parent)

            bool const copied = copies.contains(node);

            // copy the node if necessary
            if (not copied) {
                auto new_node = new Node{node->val};
                new_node->neighbors.reserve(node->neighbors.size());
                copies.emplace(node, std::move(new_node));
            }

            // copy the connection from the parent if necessary
            if (parent != nullptr && not neighbors[copies[parent]].contains(copies[node])) {
                copies[parent]->neighbors.push_back(copies[node]);
                neighbors[copies[parent]].insert(copies[node]);
            }

            // process the node's neighbors and connections, only if we've not already done so
            if (not copied)
                for (auto neighbor : node->neighbors)
            {
                stack.push({node, neighbor});
            }
        }

        return copies[node];
    }
};
