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

    vector<vector<int>> leaf;

        void dfs(TreeNode* root, int target, int current, vector<int> cur) {
        if (root == nullptr)
        {
            //cur.pop_back();
            return;
        } 
        current += root->val;
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            if(current==target)
            {
                leaf.push_back(cur);
                return;
            }
        }
        dfs(root->left, target, current, cur);
        dfs(root->right, target, current, cur);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>cur;
        if(root==nullptr) return leaf;
        if(!root->right and !root->left) 
        {
            if(root->val==targetSum) leaf.push_back({root->val});
            return leaf;
        }

        dfs(root->left,targetSum, root->val, cur);
        dfs(root->right,targetSum, root->val, cur);

        for(int i=0;i<leaf.size();i++)
            leaf[i].insert(leaf[i].begin(), root->val); 

        return leaf;
    }
};