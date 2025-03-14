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
    void traverse(TreeNode* root, string path, vector<string>& result) {
        if (root == nullptr) return;

        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);

        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        traverse(root->left, path, result);
        traverse(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root == nullptr) return result;

        traverse(root, "", result);
        return result;
    }
};
