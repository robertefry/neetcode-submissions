
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        struct BoundNode {
            TreeNode* node;
            optional<int> val_min = nullopt;
            optional<int> val_max = nullopt;
        };
        auto nodes = vector<BoundNode>{{root}};

        while (not nodes.empty())
        {
            auto [node, val_min, val_max] = nodes.back();
            nodes.pop_back();

            if (node == nullptr) {
                continue;
            }

            if (val_min.has_value() && node->val <= *val_min) {
                return false;
            }
            if (val_max.has_value() && node->val >= *val_max) {
                return false;
            }

            auto const val_mid = make_optional(node->val);
            nodes.push_back({node->left, val_min, val_mid});
            nodes.push_back({node->right, val_mid, val_max});
        }
        return true;
    }
};
