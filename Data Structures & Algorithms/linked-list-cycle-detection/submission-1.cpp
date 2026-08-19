class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode dummy{};
        ListNode* cur = head;
        while (cur)
        {
            if (cur->next == &dummy)
                return true;

            ListNode* next = cur->next;
            cur->next = &dummy;
            cur = next;
        }

        return false;
    }
};
