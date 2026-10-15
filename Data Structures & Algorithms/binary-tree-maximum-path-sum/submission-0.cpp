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
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!root)return 0;

        //go and get the sum of left sub tree
        int leftSum = max(0, dfs(root->left));
        //go and get the sum of right sub tree
        int rightSum = max(0, dfs(root->right));
        //best path that passes through this node
        ans = max(ans, root->val + leftSum + rightSum);
        //either go left or go right
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        dfs (root);
        return ans;

    }
};
