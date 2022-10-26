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
    ListNode *swapPairs(ListNode *head) {
        if(head==NULL || head->next==NULL) return head; 
        ListNode *start = head->next; 
        ListNode *next = start->next;
        start->next = head;
        head->next = swapPairs(next);
        return start; 
    }
};