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
    TreeNode* makeTree(int &index, int n, vector<int>& pre, int mini, int maxi)
    {
        if (index >= n || (pre[index] <= mini || pre[index] >= maxi)) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(pre[index++]);

        root->left = makeTree(index, n, pre, mini, root->val);
        root->right = makeTree(index, n, pre, root->val, maxi);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        int n = preorder.size();

        TreeNode* root = makeTree(index, n, preorder, INT_MIN, INT_MAX);

        return root;
    }
};
