/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include "../lib/Node.h"
#include <iostream>

using namespace std;

class Solution {
public:
    
    void Link_between(Node * ioLeft, Node * ioRight)
    {
        if(!ioLeft || !ioRight)
        {
            return;
        }
        ioLeft->next = ioRight;
        
        Link_between(ioLeft->right, ioRight->left);
    }
    
    void Link(Node * root)
    {
        if(root->left)
        {
            Link(root->left);
        }
        cout << root->val << endl;
        
        if(root->left && root->right)
        {
            root->left->next = root->right;
            root->right->next = NULL;
            Link_between(root->left, root->right);
        }
        if(root->right)
        {
            Link(root->right);
        }
        
    }
    
    Node* connect(Node* root) 
    {

        if (root)
        {
            Link(root);            
        }        

        return root;
    }
};