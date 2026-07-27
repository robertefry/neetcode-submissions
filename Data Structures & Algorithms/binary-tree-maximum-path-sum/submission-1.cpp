
class Solution {
public:
    int maxPathSum(TreeNode* root)
    {
        struct Paths {
            int conjoined; // max path including the node
            int disjoined; // max path (maybe) not including the node
        };

        auto constexpr dfs = [](this auto&& dfs, TreeNode* node) -> Paths
        {
            // assumption: node != nullptr

            /*
            conjoined = max(
                node,
                node + left.conjoined,
                node + right.conjoined,
            )

            disjoined = max(
                conjoined,
                node + left.conjoined + right.conjoined,
                left.disjoined,
                right.disjoined,
            )
            */

            auto paths = Paths {
                .conjoined = node->val,
                .disjoined = node->val,
            };
            int conjoint_sum = node->val;

            auto const account = [&](TreeNode* subnode) {
                auto const subpaths = dfs(subnode);
                paths.conjoined = max( paths.conjoined, subpaths.conjoined + node->val );
                paths.disjoined = max( paths.disjoined, subpaths.disjoined );
                conjoint_sum += subpaths.conjoined;
            };

            if (node->left != nullptr) {
                account(node->left);
            }
            if (node->right != nullptr) {
                account(node->right);
            }

            paths.disjoined = max( paths.disjoined, conjoint_sum );
            paths.disjoined = max( paths.disjoined, paths.conjoined );
            return paths;
        };

        return dfs(root).disjoined;
    }
};
