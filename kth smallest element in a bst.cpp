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
    void inOrder(TreeNode* &root, int &k, int &ans)
    {
        if (!root || ans != -1) {
            return;
        }

        if (root->left) {
            inOrder(root->left, k, ans);
        }

        k--;

        if (k == 0)
        {
            ans = root->val;
            return;
        }

        if (root->right) {
            inOrder(root->right, k, ans);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;

        inOrder(root, k, ans);

        return ans;
    }
};
