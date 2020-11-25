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
    int Check_all_child(TreeNode* root, const int & iCompare_value)
    {
        if(!root)
        {
            return 0;
        }
        
        int result =0;
        
        int maxLeft =0;
        int maxRight =0;
        int cur = abs(iCompare_value - root->val);
        
        result = cur;
        
        if(root->left)
        {
            maxLeft = Check_all_child(root->left, iCompare_value);
            if( maxLeft > result)
            {
                result = maxLeft;
            }
        }
        
        
        
        if(root->right)
        {
            maxRight = Check_all_child(root->right, iCompare_value);
            if(maxRight > result)
            {
                result = maxRight;
            }
        }
        
        
        return result;
    }
    
    void Diff(TreeNode* root,int & maxDiff)
    {
        
        if(root)
        {
            if(root->left)
            {
                Diff(root->left, maxDiff);
            }

            int temp_value = Check_all_child(root, root->val);
            if(maxDiff < temp_value)
            {
                maxDiff = temp_value;
            }
            if(root->right)
            {
                Diff(root->right, maxDiff);

                
            }
        }
    }
    
    int maxAncestorDiff(TreeNode* root) 
    {
        
        int aMaxDiff = 0;
        
        Diff(root, aMaxDiff);
        
        return aMaxDiff;
        
    }
};
