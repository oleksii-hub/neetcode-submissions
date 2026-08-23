class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        // 1. find the middle — first half keeps the extra node on odd lengths
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2. split, then reverse the second half
        ListNode* curr = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 3. interleave: first half is equal or one longer, so it runs out last
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* n1 = first->next;
            ListNode* n2 = second->next;

            first->next = second;
            second->next = n1;

            first = n1;
            second = n2;
        }
    }
};