
class Solution
{
public:

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        auto nodes = vector<TreeNode*>{{root}};

        while (not nodes.empty())
        {
            auto const node = nodes.back();
            nodes.pop_back();

            if (this->isEqual(node, subRoot)) {
                return true;
            }

            if (node == nullptr) {
                continue;
            }
            nodes.push_back(node->left);
            nodes.push_back(node->right);
        }
        return false;
    }

    bool isEqual(TreeNode* root_1, TreeNode* root_2)
    {
        auto nodes = vector<tuple<TreeNode*,TreeNode*>>{{root_1,root_2}};

        while (not nodes.empty())
        {
            auto const [node_1, node_2] = nodes.back();
            nodes.pop_back();

            if ((node_1 == nullptr) != (node_2 == nullptr)) {
                return false;
            }
            if (node_1 == nullptr || node_2 == nullptr) {
                continue;
            }

            if (node_1->val != node_2->val) {
                return false;
            }
            nodes.push_back({node_1->left, node_2->left});
            nodes.push_back({node_1->right, node_2->right});
        }
        return true;
    }

};
