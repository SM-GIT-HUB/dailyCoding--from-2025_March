class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        Node* curr = root;
        
        while (curr && curr->key != key)
        {
            if (key < curr->key)
            {
                suc = curr;
                curr = curr->left;
            }
            else
            {
                pre = curr;
                curr = curr->right;
            }
        }
        
        if (!curr) {
            return;
        }
        
        Node* left = curr->left;
        Node* right = curr->right;
        
        while (left)
        {
            pre = left;
            left = left->right;
        }
        
        while (right)
        {
            suc = right;
            right = right->left;
        }
    }
};
