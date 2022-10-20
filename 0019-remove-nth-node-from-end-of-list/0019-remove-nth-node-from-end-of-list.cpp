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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        ListNode* cur = head;
        while (cur) {
          ++l;
          cur = cur->next;
        }
        if (n == l) {
          ListNode* ans = head->next;
          delete head;
          return ans;
        }    
        l -= n;
        cur = head;
        while (--l) cur = cur->next;
        ListNode* node = cur->next;
        cur->next = node->next;
        delete node;
        return head;
    }
};