/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool isSym(BinaryTreeNode<int>* &r1, BinaryTreeNode<int>* &r2)
{
    if (!r1 && !r2) {
        return true;
    }

    if (!r1 || !r2) {
        return false;
    }

    bool one = isSym(r1->left, r2->right);
    bool two = isSym(r1->right, r2->left);

    return (r1->data == r2->data && (one && two));
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.
    bool ans = isSym(root, root);

    return ans;
}
