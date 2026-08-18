class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* cur = nullptr;
        ListNode* other = nullptr;
        if (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cur = list1;
                other = list2;
            }
            else
            {
                cur = list2;
                other = list1;
            }
        }
        else if (list1 != nullptr)
        {
            cur = list1;
        }
        else if (list2 != nullptr)
        {
            cur = list2;
        }
        ListNode* head = cur;

        while(cur)
        {
            if (cur->next == nullptr)
            {
                cur->next = other;
                break;
            }
            
            if (other == nullptr)
            {
                break;
            }

            if (cur->next->val > other->val)
            {
                ListNode* next = cur->next;
                cur->next = other;
                other = next;
            }

            cur = cur->next;
        }

        return head;
    }
};
