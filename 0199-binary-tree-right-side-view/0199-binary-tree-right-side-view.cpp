class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {}; // Handle empty tree case

        vector<int> right;
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int levelSize = Q.size();
            TreeNode* current = nullptr;

            for (int i = 0; i < levelSize; i++) 
            {
                current = Q.front();
                Q.pop();

                if (current->left) Q.push(current->left);
                if (current->right) Q.push(current->right);
            }
            right.push_back(current->val);
        }

        return right;
    }
};
