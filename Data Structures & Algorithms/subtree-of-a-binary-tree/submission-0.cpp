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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //if the subRoot is empty return true an empty tree is inside every tree
        if(!subRoot)return true;

        //if the root is empty means we've walked off the bottom of the root and subroot is not empty 
        if(!root)return false;

        //if both are not empty check if they're same or not
        if(isSameTree(root, subRoot))return true;

        //here we check both side 
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root and !subRoot)return true;
        if(root and subRoot and root->val == subRoot->val){
            return isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right);
        }
        return false;
    }
};
