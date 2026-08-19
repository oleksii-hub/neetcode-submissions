class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode dummy{};
        ListNode* cur = head;
        ListNode* next = cur != nullptr ? cur->next : nullptr;
        while (cur)
        {
            if (cur->next == &dummy)
                return true;

            next = cur->next;
            cur->next = &dummy;
            cur = next;
        }

        return false;
    }
};
