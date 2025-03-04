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
class BSTIterator {
public:
    vector<TreeNode*> stack;

    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;

        while (curr)
        {
            stack.push_back(curr);
            curr = curr->left;
        }
    }
    
    int next() {
        TreeNode* curr = stack.back();
        stack.pop_back();
        int ans = curr->val;

        curr = curr->right;

        while (curr)
        {
            stack.push_back(curr);
            curr = curr->left;
        }

        return ans;
    }
    
    bool hasNext() {
        return stack.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
