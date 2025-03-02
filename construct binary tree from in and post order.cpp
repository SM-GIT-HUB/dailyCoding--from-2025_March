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
    TreeNode* makeTree(int &index, int start, int end, vector<int>& inn, vector<int>& post)
    {
        if (index < 0 || start > end) {
            return nullptr;
        }

        if (start == end) {
            return new TreeNode(post[index--]);
        }

        int x = post[index--];
        int i = 0;
        
        for (i = start; i <= end && inn[i] != x; i++);
        
        TreeNode* root = new TreeNode(x);

        root->right = makeTree(index, i + 1, end, inn, post);
        root->left = makeTree(index, start, i - 1, inn, post);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = inorder.size() - 1;

        TreeNode* ans = makeTree(index, 0, index, inorder, postorder);

        return ans;
    }
};
