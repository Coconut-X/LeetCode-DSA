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
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);
        vector<int> ans;
        int m=INT_MIN;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==nullptr)
            {
                ans.push_back(m);
                if(!q.empty())
                    q.push(nullptr);
                m=INT_MIN;
            }
            else 
            {    
                m=max(m,temp->val);

                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }

        }

       return ans;
        
    }
};