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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        vector<vector<int>> ans;
        if(root==nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        vector<int>row;

        while(!q.empty())
        {
            TreeNode* t = q.front();
            q.pop();

            if(t==nullptr)
            {
                ans.push_back(row);
                row.clear();
                if(!q.empty())
                    q.push(nullptr);
            }

            else
            {
                row.push_back(t->val);
                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);
            }
        }

        reverse(ans.begin(),ans.end());

        return ans;
        
    }
};