
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        auto levels = vector<vector<int>>{};
        auto nodes = deque<tuple<size_t,TreeNode*>>{{0,root}};

        while (not nodes.empty())
        {
            auto const [level,node] = nodes.front();
            nodes.pop_front();

            if (node == nullptr) {
                continue;
            }

            levels.resize(level+1);
            levels[level].push_back(node->val);

            nodes.push_back({level+1, node->left});
            nodes.push_back({level+1, node->right});
        }

        return levels;
    }
};
