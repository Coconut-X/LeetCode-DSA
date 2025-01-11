class Solution {
public:
    int maxLevelSum(TreeNode* root) {  

        int m = INT_MIN; 
        int level = 1, maxLev = 1; 
        int sum = 0; 
        
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(nullptr); 

        while (!Q.empty()) {
            TreeNode* current = Q.front();
            Q.pop();

            if (current) {
                sum += current->val;
                if (current->left) Q.push(current->left);
                if (current->right) Q.push(current->right);
            } else {

                if (sum > m) {
                    m = sum;
                    maxLev = level;
                }
                sum = 0;
                level++;

                if (!Q.empty()) Q.push(nullptr);
            }
        }

        return maxLev;
    }
};
