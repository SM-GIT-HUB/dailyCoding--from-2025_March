#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    BinaryTreeNode<int>* curr = node;
    int ans = INT_MAX;

    while (curr)
    {
        if (x <= curr->data)
        {
            ans = curr->data;
            curr = curr->left;
        }
        else
            curr = curr->right;
    }

    return ans == INT_MAX? -1 : ans;
}
