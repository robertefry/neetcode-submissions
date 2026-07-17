
#include <utility>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        // dfs inorder traversal, return the kth encountered

        // assumption: there are at least k elements in the tree
        // assumption: root != nullptr && k > 0

        auto nodes = vector<TreeNode*>{};
        TreeNode* node = nullptr;

        while (root != nullptr || not nodes.empty())
        {
            while (root != nullptr) {
                nodes.push_back(root);
                root = root->left;
            }

            node = nodes.back();
            nodes.pop_back();

            if (--k == 0) {
                return node->val;
            }
            root = node->right;
        }
        unreachable();
    }
};
