/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr;
        }

        Node* main = new Node(node->val);
        unordered_map<int, Node*> mapp;

        mapp[node->val] = main;

        queue<Node*> q;
        q.push(node);

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();

            for (auto &v : curr->neighbors)
            {
                if (mapp[v->val]) {
                    mapp[curr->val]->neighbors.push_back(mapp[v->val]);
                }
                else
                {
                    Node* newnode = new Node(v->val);
                    mapp[curr->val]->neighbors.push_back(newnode);
                    q.push(v);
                    mapp[v->val] = newnode;
                }
            }
        }

        return main;
    }
};
