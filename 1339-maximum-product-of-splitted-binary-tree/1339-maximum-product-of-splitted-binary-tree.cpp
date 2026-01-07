class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;

    long long getTotalSum(TreeNode* node) {
        if (!node) return 0;
        return node->val + getTotalSum(node->left) + getTotalSum(node->right);
    }

    long long findMaxProduct(TreeNode* node) {
        if (!node) return 0;

        long long currentSubtreeSum = node->val + findMaxProduct(node->left) + findMaxProduct(node->right);
        
        long long currentProduct = currentSubtreeSum * (totalSum - currentSubtreeSum);
        
        if (currentProduct > maxProd) {
            maxProd = currentProduct;
        }

        return currentSubtreeSum;
    }

    int maxProduct(TreeNode* root) {
        maxProd = 0;
        totalSum = getTotalSum(root);
        
        findMaxProduct(root);
        
        return (int)(maxProd % 1000000007);
    }
};