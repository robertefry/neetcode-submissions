
class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        auto nodes = vector<tuple<size_t,TreeNode*>>{{1,root}};
        size_t max_depth = 0;

        while (not nodes.empty())
        {
            auto const [depth,node] = nodes.back();
            nodes.pop_back();

            if (node == nullptr) {
                continue;
            }
            if (node->left == nullptr && node->right == nullptr) {
                max_depth = std::max(max_depth, depth);
                continue;
            }

            nodes.push_back({depth+1,node->right});
            nodes.push_back({depth+1,node->left});
        }
        return max_depth;
    }
};
