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


class Solution {
public:
    
    ListNode * New_reverse_list(ListNode * input_List)
    {
        ListNode * Head = NULL;  
        ListNode * cur = input_List;
        
        while(cur)
        {
            ListNode * temp = new ListNode(cur->val);
            
            if(Head == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = Head;
            }
            Head = temp;
            
            cur = cur->next;
        }
        
        return Head;
    }
    
    void My_List_Print(ListNode * input_List)
    {
        ListNode * cur = input_List;
        
        cout << "Debug print: \n";
        while(cur)
        {
            cout << cur->val << endl;
            cur = cur->next;
        }
    }
    
    ListNode * AddTwoList(ListNode * L1, ListNode * L2)
    {
        ListNode * result = NULL;
        
        ListNode * cur1 = L1;
        ListNode * cur2 = L2;
        
        int overflow =0;
        
        while( (cur1 != NULL ) || (cur2 != NULL)  || (overflow != 0))
        {
            int sum =0;
            if(cur1 && cur2)
            {
                sum = cur1->val + cur2->val + overflow;

            }
            else if(cur1 && !cur2)
            {
                sum = overflow + cur1->val;
            }
            else if (!cur1 && cur2 )
            {
                sum = overflow + cur2->val;
            }
            else // if (!(cur1 && cur2) )
            {
                sum = overflow;
            }
            
            overflow = sum/10;
            sum = sum %10;

            ListNode * temp = new ListNode(sum);
            if(result == NULL)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = result;
            }
            
            result = temp;
            
            if(cur1)
            {
                cur1 = cur1->next;
            }
            
            if(cur2)
            {
                cur2 = cur2->next;
            }
        }
        
        return result;
    }

    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {   
        ListNode * My_List_1 = New_reverse_list(l1);
        ListNode * My_List_2 = New_reverse_list(l2);
        
        ListNode * Sum = AddTwoList(My_List_1, My_List_2);
        
        return Sum;
        
    }
};
