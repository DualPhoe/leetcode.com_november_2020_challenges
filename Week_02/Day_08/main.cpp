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
    
    void Traverse_Tree(TreeNode * root)
    {
        if( root->left)
        {
            Traverse_Tree(root->left);
        }
        cout << "value: " << root->val << endl;
        if( root->right)
        {
            Traverse_Tree(root->right);
        }
    }
    
    void Calculate(TreeNode * root, int & ioDif, int & ioSum, int & res)
    {
        int aSum_left = 0;
        int aSum_right = 0;
        if(root->left)
        {
            Calculate(root->left, ioDif, aSum_left, res);
        }
        
        ioSum+= aSum_left;
        ioSum+= root->val;
        
        if(root->right)
        {
            Calculate(root->right, ioDif, aSum_right, res);
        }
        else
        {
            aSum_right =0;
        }
        
        ioDif =  abs(aSum_left - aSum_right);
        ioSum += aSum_right;
        res += ioDif;
 
        
    }
    
    int findTilt(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        
        int result = 0;
        int diff = 0;
        int sum = 0;
        
        Calculate(root, diff, sum, result);
        

        return result;
    }
};
