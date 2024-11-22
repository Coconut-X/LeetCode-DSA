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
        vector<int> leftt;
        vector<int> rightt;

    void storeLeft(TreeNode* L)
    {
        if(!L)
            return;

        if(L->left and !L->right)
        {
           TreeNode* n= new TreeNode(-100);
           L->right=n;
        }

         else if(!L->left and L->right)
        {
           TreeNode* n= new TreeNode(-100);
           L->left=n;
        }
           
        storeLeft(L->left);
        leftt.push_back(L->val);
        cout<<L->val<<endl;
        storeLeft(L->right);

    }


     void storeRight(TreeNode* R)
    {
        if(!R)
            return;

        if(R->left and !R->right)
        {
           TreeNode* n= new TreeNode(-100);
           R->right=n;
        }

         else if(!R->left and R->right)
        {
           TreeNode* n= new TreeNode(-100);
           R->left=n;
        }

        storeRight(R->right);
        rightt.push_back(R->val);
        storeRight(R->left);

    }

    
    bool check(TreeNode* L, TreeNode* R)
    {
        if(!L and !R)
            return true;

        if((L and !R) or (!L and R) or (L->val!=R->val))
            return false;

        return check(L->left, R->right) and check(L->right, R->left);
    }

    bool isSymmetric(TreeNode* root) {

        // if(root==nullptr || (root->right==nullptr && root->left==nullptr))
        //     return true;

        // if((root->right && !root->left) ||(!root->right && root->left) )
        //     return false;

        // if(root->left->val!=root->right->val)
        //     return false;

        
        // storeLeft(root->left);
        // storeRight(root->right);

        // if(leftt.size() != rightt.size())
        //     return false;

        // for(int i=0;i< leftt.size();i++)
        // {
        //     if(leftt[i]!=rightt[i])
        //         return false;
        // }

        // return true;

        if(root==nullptr) return true;

        return check(root->left, root->right);

    }
};