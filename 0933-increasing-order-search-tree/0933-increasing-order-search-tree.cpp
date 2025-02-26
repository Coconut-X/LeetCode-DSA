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

    void insert(TreeNode* &root, int data)
    {
        if(root==nullptr)
        {
            root=new TreeNode(data);
            return;
        }
        insert(root->right, data);

        //root->right=new TreeNode(data);
    }

    void inorder(TreeNode* orig, TreeNode* &newRoot)
    {
        if(orig==nullptr) return;
        inorder(orig->left, newRoot);
        insert(newRoot, orig->val);
        inorder(orig->right, newRoot);
    }


    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* newRoot=nullptr;
        inorder(root, newRoot);
        return newRoot;
        
    }
};