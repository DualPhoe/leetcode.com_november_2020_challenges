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
    
    void my_sum(TreeNode * root, int & ioSum, const int & iLow, const int & iHight)
    {
        if(!root)
        {
            return;
        }
        my_sum(root->left, ioSum, iLow, iHight);
        if( iLow <= root->val && root->val <= iHight )
        {
            // cout << root->val <<endl;
            ioSum += root->val; 
        }
        my_sum(root->right, ioSum, iLow, iHight);
        
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int aSum =0;
        my_sum(root, aSum, low, high);
        return aSum;
    }
};