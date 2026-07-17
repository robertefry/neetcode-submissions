
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // assumption: p and q are in root

        if (root == nullptr) {
            return nullptr;
        }
        if (p == nullptr) {
            return q;
        }
        if (q == nullptr) {
            return p;
        }

        if (p->val < root->val && q->val < root->val) {
            return this->lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val && q->val > root->val) {
            return this->lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
