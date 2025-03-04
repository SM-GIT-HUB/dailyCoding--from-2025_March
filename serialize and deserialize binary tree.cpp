/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* top = q.front();
            q.pop();

            if (top == nullptr)
            {
                ans += "N,";
                continue;
            }

            ans += to_string(top->val) + ",";

            q.push(top->left);
            q.push(top->right);
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "N,") {
            return nullptr;
        }

        string curr1 = "";
        string curr2 = "";

        int n = data.size();
        int index = 0;

        while (index < n && data[index] != ',')
        {
            curr1 += data[index++];
        }

        index++;

        TreeNode* root = new TreeNode(stoi(curr1));
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            if (data[index] == ',')
            {
                index++;
                continue;
            }

            TreeNode* top = q.front();
            q.pop();

            curr1 = "";
            curr2 = "";

            while (index < n && data[index] != ',')
            {
                curr1 += data[index++];
            }

            index++;

            while (index < n && data[index] != ',')
            {
                curr2 += data[index++];
            }

            index++;

            if (curr1 != "N" && curr1.size())
            {
                top->left = new TreeNode(stoi(curr1));
                q.push(top->left);
            }

            if (curr2 != "N" && curr2.size())
            {
                top->right = new TreeNode(stoi(curr2));
                q.push(top->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
