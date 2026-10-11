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
    TreeNode* invertTree(TreeNode* root) {
        //base case
       if(root == nullptr)return root;
       //go left
       TreeNode* leftChild = invertTree(root->left);
       //go right
       TreeNode* rightChild = invertTree(root->right);
       //point leftChild of the node to the right pointer
       root->right = leftChild;
       //point rightChild of the node to the left pointer
       root->left = rightChild;
       //return the root
       return root; 
    }
}; 
