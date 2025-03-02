class Solution{
    public:
    bool getAns(Node* &root)
    {
        if (!root || (!root->left && !root->right)) {
            return true;
        }
        
        int left = root->left? root->left->data : 0;
        int right = root->right? root->right->data : 0;
        
        if (root->data != (left + right)) {
            return false;
        }
        
        left = getAns(root->left);
        right = getAns(root->right);
        
        return (left && right);
    }
    
    int isSumProperty(Node *root)
    {
        bool ans = getAns(root);
        
        return ans;
    }
};
