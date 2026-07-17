
#include <utility>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k)
    {
        // dfs inorder traversal, return the kth encountered

        // assumption: there are at least k elements in the tree
        // assumption: root != nullptr && k > 0

        auto nodes = vector<TreeNode*>{};
        auto build = root;

        TreeNode* element = nullptr;

        while (build != nullptr || not nodes.empty())
        {
            while (build != nullptr) {
                nodes.push_back(build);
                build = build->left;
            }

            element = nodes.back();
            nodes.pop_back();

            if (--k == 0) {
                return element->val;
            }
            build = element->right;
        }
        unreachable();
    }
};
