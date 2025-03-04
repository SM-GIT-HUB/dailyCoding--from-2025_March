class Solution {
  public:
    bool findTarget(Node *root, int target) {
        // your code here.
        vector<Node*> stackNext;
        vector<Node*> stackPrev;
        
        Node* curr = root;
        
        while (curr)
        {
            stackNext.push_back(curr);
            curr = curr->left;
        }
        
        curr = root;
        
        while (curr)
        {
            stackPrev.push_back(curr);
            curr = curr->right;
        }
        
        int sum = 0;
        int leftVal = 0;
        int rightVal = 0;
        
        auto popNext = [&]() {
            curr = stackNext.back();
            stackNext.pop_back();
            
            curr = curr->right;
            
            while (curr)
            {
                stackNext.push_back(curr);
                curr = curr->left;
            }
        };
        
        auto popPrev = [&]() {
            curr = stackPrev.back();
            stackPrev.pop_back();
            
            curr = curr->left;
            
            while (curr)
            {
                stackPrev.push_back(curr);
                curr = curr->right;
            }
        };
        
        while (!stackNext.empty() && !stackPrev.empty())
        {
            leftVal = stackNext.back()->data;
            rightVal = stackPrev.back()->data;
            
            if (leftVal >= rightVal) {
                return false;
            }
            
            sum = leftVal + rightVal;
            
            if (sum == target) {
                return true;
            }
            else if (sum < target) {
                popNext();
            }
            else
                popPrev();
        }
        
        return false;
    }
};
