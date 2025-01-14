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

    bool dfs(TreeNode* root, int target, int current) {
        if (root == nullptr) return false; 
        current += root->val;
        if (root->left == nullptr && root->right == nullptr) return current == target;
        return dfs(root->left, target, current) || dfs(root->right, target, current);
    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        if(!root->right and !root->left) return root->val==targetSum;

        return dfs(root->left,targetSum, root->val) or dfs(root->right,targetSum, root->val); 
      
    }
};