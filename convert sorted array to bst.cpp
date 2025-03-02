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
TreeNode<int>* makeTree(int start, int end, vector<int>& arr)
{
    if (start > end) {
        return nullptr;
    }

    if (start == end) {
        return new TreeNode<int>(arr[start]);
    }

    int index = start + ((end - start) >> 1);

    TreeNode<int>* root = new TreeNode<int>(arr[index]);

    root->left = makeTree(start, index - 1, arr);
    root->right = makeTree(index + 1, end, arr);

    return root;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    TreeNode<int>* ans = makeTree(0, n - 1, arr);
    return ans;
}






