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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr) return true;
        if(p == nullptr and q!= nullptr) return false;
        if(p != nullptr and q == nullptr) return false;

        if(p->val == q->val){
        //go left on both
        bool leftok = isSameTree(p->left, q->left);
        //go right on both
        bool rightok = isSameTree(p->right, q->right);
        return (leftok and rightok);
        }
        else return false;
        

    }
};
