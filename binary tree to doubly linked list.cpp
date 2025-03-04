class Solution {
  public:
    Node* getPred(Node* &root)
    {
        Node* temp = root->left;
        
        while (temp->right && temp->right != root)
        {
            temp = temp->right;
        }
        
        return temp;
    }
  
    Node* bToDLL(Node* root) {
        // code here
        Node* main = new Node(-1);
        Node* temp = main;
        
        Node* curr = root;
        
        while (curr)
        {
            if (!curr->left)
            {
                temp->right = curr;
                curr->left = temp;
                temp = temp->right;
                curr = curr->right;
                
                continue;
            }
            
            Node* pred = getPred(curr);
            
            if (pred->right == nullptr)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                temp->right = curr;
                curr->left = temp;
                temp = temp->right;
                curr = curr->right;
            }
        }
        
        main = main->right;
        main->left = nullptr;
        
        return main;
    }
};
