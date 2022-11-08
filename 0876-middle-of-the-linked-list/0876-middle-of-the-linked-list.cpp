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
    ListNode* middleNode(ListNode* head) {
//         int len = 0;
//         ListNode* temp = head;
//         while (temp) {
//             ++len;
//             temp = temp -> next;
//         }
        
//         temp = head;
//         len /= 2;
//         while (len--) {
//             temp = temp->next;
//         }
        
//         return temp;
        
        
        vector<ListNode*> A = {head};
        while (A.back()->next != nullptr) {
            A.push_back(A.back()->next);
        }
        return A[A.size() / 2];
    }
};