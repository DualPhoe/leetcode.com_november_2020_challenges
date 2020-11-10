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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode * newHead = NULL;
        ListNode * temp = head;
        while (temp)
        {
            int temp_val = temp->val;
            
            if(newHead == NULL)
            {
                ListNode * first_node = new ListNode(temp_val) ;
                newHead = first_node;
                
            }
            else if(newHead && !newHead->next)
            {
                if(temp_val < newHead->val)
                {
                    ListNode * cur = new ListNode(temp_val, newHead);
                    newHead = cur;
                }
                else 
                {
                    ListNode * cur = new ListNode(temp_val);
                    newHead->next = cur;
                }

            }
            else
            {
                ListNode * cur = newHead;
                while(cur->next && cur->next->val < temp_val)
                {
                    cur = cur->next;
                }
                
                if(cur->next == NULL)
                {
                    ListNode * last_node = new ListNode(temp_val);
                    cur->next = last_node;
                }
                else if(cur == newHead)
                {
                    if(temp_val < newHead->val)
                    {
                        ListNode * cur = new ListNode(temp_val, newHead);
                        newHead = cur;
                    }
                    else 
                    {
                        ListNode * cur = new ListNode(temp_val, newHead->next);
                        newHead->next = cur;
                    }
                }
                else
                {
                    ListNode * cur_next = cur->next;
                    ListNode * mid_node = new ListNode(temp_val, cur_next);
                    cur-> next = mid_node;

                }
            }
            
            temp = temp->next;
        }
        
        return newHead;
    }
};