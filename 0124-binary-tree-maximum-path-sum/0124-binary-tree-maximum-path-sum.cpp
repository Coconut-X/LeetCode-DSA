// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

class Solution {
public:
    
    int move(TreeNode* node, int &maxi){
        if(node == nullptr) return 0;
        int l = max(0, move(node->right, maxi));
        int r = max(0, move(node->left, maxi));
        maxi = max(maxi, node->val + l + r); //skip take logic
        return node->val + max(l,r);
    }

    int maxPathSum(TreeNode* root) {
        // write your code here 
        int maxi = INT_MIN;
        move(root, maxi);
        return maxi;
    }
};