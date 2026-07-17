
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // assumption: p and q are in root
        // assumption: all values are unique

        if (root == nullptr) {
            return nullptr;
        }
        if (p == nullptr) {
            return q;
        }
        if (q == nullptr) {
            return p;
        }
        if (p->val == q->val) {
            return p;
        }

        return this->_lowest_common_ancestor(root, p->val, q->val);
    }
private:
    TreeNode* _lowest_common_ancestor(TreeNode* root, int p, int q)
    {
        if (root == nullptr) {
            return nullptr;
        }
        if (p < root->val && q < root->val) {
            return this->_lowest_common_ancestor(root->left, p, q);
        }
        if (p > root->val && q > root->val) {
            return this->_lowest_common_ancestor(root->right, p, q);
        }
        return root;
    }
};
