#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    TreeNode<int>* curr = root;
    int ans = INT_MIN;

    while (curr)
    {
        if (curr->val == x) {
            return x;
        }

        if (curr->val < x)
        {
            if (curr->val > ans) {
                ans = curr->val;
            }
            curr = curr->right;
        }
        else
            curr = curr->left;
    }

    return ans;
}
