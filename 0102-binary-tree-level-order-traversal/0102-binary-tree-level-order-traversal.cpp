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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> levels;
        if(root==nullptr) return levels;
        vector<int> curr;

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); //mark end of level

        while(!q.empty())
        {   
            TreeNode* node=q.front();
            q.pop();

            if(node==nullptr)
            {
                levels.push_back(curr);
                curr.clear();
                if(!q.empty())
                    q.push(nullptr);
            }

            else
            {
                curr.push_back(node->val);

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);

            }


        }

        return levels;
        
        
    }
};