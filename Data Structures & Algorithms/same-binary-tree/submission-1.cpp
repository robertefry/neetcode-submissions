
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        auto nodes = vector<tuple<TreeNode*,TreeNode*>>{{p,q}};

        while (not nodes.empty())
        {
            auto const [p,q] = nodes.back();
            nodes.pop_back();

            if ((p == nullptr) != (q == nullptr)) {
                return false;
            }
            if (p == nullptr || q == nullptr) {
                continue;
            }

            if (p->val != q->val) {
                return false;
            }

            nodes.push_back({p->left,q->left});
            nodes.push_back({p->right,q->right});
        }

        return true;
    }
};
