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
        ListNode* fast = head;
        ListNode dummy{};
        dummy.next = head;
        ListNode* slow = &dummy;
        int len = 1;
        while (fast->next)
        {
            fast = fast->next;
            if (len < n)
            {
                ++len;
                continue;
            }

            slow = slow->next;
        }
        slow->next = slow->next->next;

        return dummy.next;
    }
};
