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
    int getnum(vector<bool>&num){
        int sum = 0;
        for(int i = 0; i < num.size(); i++){
            sum+= num[i]*pow(2,num.size() - i - 1);
        }
        cout<<sum<<endl;
        return sum;
    }
    int move(TreeNode* root, vector<bool> num){

        if(!root->left and !root->right){
            num.push_back(root->val);
            return getnum(num);
        }
        num.push_back(root->val);
        int left = root->left? move(root->left, num):0;
        int right = root->right? move(root->right, num):0;
        num.pop_back();
        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<bool>num;
        return move(root, num);
    }
};