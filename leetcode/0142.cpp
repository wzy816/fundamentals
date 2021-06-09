/*
142. Linked List Cycle II

linked list, return the node where the cycle begins. If there is no cycle, return null.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        // fast&slow pointer
        ListNode* fast = head;
        ListNode* slow = head;
        int i = 0;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            i++;
            if(fast == slow){
                break;
            }
        }
        // i=cycle length
        if(!fast || !fast->next)
            return nullptr;
        
        ListNode* n = head;
        ListNode* m = head;
        // offset by i pos
        while(i--){
            n = n->next;
        }
        while(m!=n){
            m = m->next;
            n = n->next;
        }
        return m;
    }
};
