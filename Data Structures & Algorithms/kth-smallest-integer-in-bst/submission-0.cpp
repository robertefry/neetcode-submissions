
class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        // dfs inorder traversal, return the kth encountered

        // assumption: there are at least k elements in the tree
        // assumption: root != nullptr && k > 0

        auto nodes = vector<tuple<bool,TreeNode*>>{{true,root}};

        TreeNode* element = nullptr;
        int count = 0;

        while (count < k)
        {
            auto [precharge, node] = nodes.back();
            nodes.pop_back();

            if (node == nullptr) {
                continue;
            }

            if (precharge) {
                for (; node != nullptr; node = node->left) {
                    nodes.push_back({false,node});
                }
                continue;
            }
            nodes.push_back({true,node->right});

            element = node;
            count += 1;
        }

        return element->val;
    }
};
