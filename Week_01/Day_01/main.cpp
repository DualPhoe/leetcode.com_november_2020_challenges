/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int result =0;
        ListNode * temp = head;
        
        while(temp != NULL)
        {
            // cout<< "Temp result: " << result << endl;
            result *= 2;
            if(temp->val == 1 || temp->val == 0 )
            {
                result += temp->val;
            }
            
            temp = temp->next;
        }
        
        return result;
    }
};
