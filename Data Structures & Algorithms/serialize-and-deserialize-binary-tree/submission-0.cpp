/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        DFSEncoding(root, res);
        return buildString(res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>vals = split(data);
        int i = 0;
        return DFSDecoding(vals, i);
    }

    void DFSEncoding(TreeNode* root, vector<string>& res) {
        if (!root) {
            res.push_back("!");
            return;
        }
        res.push_back(to_string(root->val));
        DFSEncoding(root->left, res);
        DFSEncoding(root->right, res);
    }

    TreeNode* DFSDecoding(vector<string>&vals, int&i ){
        if(vals[i] == "!"){
            i++;
            return NULL;
        }
        TreeNode* node = new TreeNode(stoi(vals[i]));
        i++;
        node->left = DFSDecoding(vals, i);
        node->right = DFSDecoding(vals, i);

        return node;
    }
    string buildString(vector<string>& res) {
        int n = res.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            s += res[i];
            if (i != n - 1) {
                s += ',';
            }
        }
        return s;
    }

    vector<string>split(string &s){
        vector<string>val;
        int n = s.size();
        string cur = "";
        for(int i=0; i<n; i++){
            if(s[i] == ','){
                val.push_back(cur);
                cur = "";
            }
            else cur +=s[i];
        }
        val.push_back(cur);
        return val;
    }
};
