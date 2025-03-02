#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void makeMirror(BinaryTreeNode<int>* &root)
{
    if (!root) {
        return;
    }

    makeMirror(root->left);
    makeMirror(root->right);

    BinaryTreeNode<int>* left = root->left;
    BinaryTreeNode<int>* right = root->right;

    root->right = left;
    root->left = right;
}

void mirrorTree(BinaryTreeNode<int> *root) {
    // Write your code here.
    makeMirror(root);
}
