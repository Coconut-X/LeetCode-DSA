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
    vector<int> arr;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        arr.push_back(node->val);
        traverse(node->right);
        traverse(node->left);
    }
    int minDiffInBST(TreeNode* root) {
        traverse(root);
        sort(arr.begin(),arr.end());
        int m = INT_MAX;
        
        for(int i = 0; i < arr.size() - 1; i++) m = min(m, arr[i+1]-arr[i]);
        return m;

    }
};