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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* answer = new ListNode();
		ListNode* answerBegin = answer;

		answerBegin = answer;
		int val;
		while (l1 != nullptr || l2 != nullptr)
		{
			val = 0;
			if (l1 != nullptr)
			{
				val += l1->val;
				l1 = l1->next;
			}
			if (l2 != nullptr)
			{
				val += l2->val;
				l2 = l2->next;
			}

			val += answer->val;
			answer->val = val % 10;

			if (l1 != nullptr || l2 != nullptr || val >= 10)
			{
				answer->next = new ListNode(val / 10);
				answer = answer->next;
			}
		}
		return answerBegin;
    }
};