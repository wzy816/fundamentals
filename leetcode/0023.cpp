/*
23. Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
*/

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

struct compare
{
    bool operator()(const ListNode* n1, const ListNode* n2)
    {
        return n1->val > n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return NULL;
        }

        priority_queue<ListNode*, vector<ListNode*>,compare> pq;
        
        for(int i=0;i< lists.size();++i){
            ListNode* l = lists[i];
            if(l != NULL){
                pq.push(l);
            }
        }
        
        ListNode* head = new ListNode();
        ListNode* p = head;
        while(pq.size()>0){
            ListNode* n = pq.top();
            pq.pop();
            p->next = n;
            if(n->next){
                pq.push(n->next);
            }
            p = p->next;
        }
        return head->next;
        
    }
};
