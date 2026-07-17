
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        auto nodes = queue<TreeNode*>{{root}};

        while (not nodes.empty())
        {
            auto const node = nodes.front();
            nodes.pop();

            if (node == nullptr) {
                continue;
            }
            std::swap(node->left, node->right);
            nodes.push(node->left);
            nodes.push(node->right);
        }
        return root;
    }
};
