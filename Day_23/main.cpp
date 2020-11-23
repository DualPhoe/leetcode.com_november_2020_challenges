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

    int Traverse(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        
        
        int res =0;

        int sum = root->val;
        
        if(root->left)
        {
            sum += (Traverse(root->left->left) + Traverse(root->left->right) );
        }
        
        if(root->right)
        {
            sum += (Traverse(root->right->left) + Traverse(root->right->right)); 
        }
               

        int sum_skip = Traverse(root->left) + Traverse(root->right);


        if(sum > sum_skip)
        {
            res = sum;
        }
        else
        {
            res = sum_skip;
        }
        
        return res;
        
    }
    
    int rob(TreeNode* root) {
        int res = 0;
        
        
        res = Traverse(root);
        
        
        return res;
    }
};
