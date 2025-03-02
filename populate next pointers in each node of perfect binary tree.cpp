/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* point = root;
        Node* curr1 = nullptr;
        Node* curr2 = nullptr;

        while (point)
        {
            curr2 = nullptr;
            curr1 = point;

            while (curr1 && curr1->left)
            {
                if (curr2) {
                    curr2->right->next = curr1->left;
                }

                curr1->left->next = curr1->right;
                curr2 = curr1;
                curr1 = curr1->next;
            }

            point = point->left;
        }

        return root;
    }
};
