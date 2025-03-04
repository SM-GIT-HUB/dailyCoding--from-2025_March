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
class obj {
public:
    bool isBst;
    int sum;
    int mini;
    int maxi;
};

class Solution {
public:
    obj getSum(TreeNode* &root, int &ans)
    {
        if (!root) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        obj left = getSum(root->left, ans);
        obj right = getSum(root->right, ans);

        if (!left.isBst || !right.isBst || root->val <= left.maxi || root->val >= right.mini) {
            return {false, 0, 0, 0};
        }

        int mini = min(left.mini, root->val);
        int maxi = max(right.maxi, root->val);
        int sum = root->val + left.sum + right.sum;

        if (sum > ans) {
            ans = sum;
        }

        return {true, sum, mini, maxi};
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        getSum(root, ans);

        return ans;
    }
};
