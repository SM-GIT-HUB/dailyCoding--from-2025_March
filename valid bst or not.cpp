/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValid(TreeNode* &root, long long mini, long long maxi)
    {
        if (!root) {
            return true;
        }

        if (root->val <= mini || root->val >= maxi) {
            return false;
        }

        bool left = isValid(root->left, mini, root->val);
        
        if (!left) {
            return false;
        }

        bool right = isValid(root->right, root->val, maxi);

        return right;
    }

    bool isValidBST(TreeNode* root) {
        bool ans = isValid(root, 1LL * INT_MIN - 1, 1LL * INT_MAX + 1);

        return ans;
    }
};
