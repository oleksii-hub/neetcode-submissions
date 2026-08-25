class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy{0, head};
        ListNode* slow = &dummy;
        ListNode* fast = head;

        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* target = slow->next;
        slow->next = target->next;

        return dummy.next;
    }
};