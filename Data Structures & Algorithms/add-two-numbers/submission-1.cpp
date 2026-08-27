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
        // 1 -> 2 > 3
        // 5

        ListNode dummy{0};
        ListNode* tail = &dummy;
        int add = 0;
        while(true)
        {
            int v1 = l1 != nullptr ? l1->val : 0;
            int v2 = l2 != nullptr ? l2->val : 0;
            int sum = v1 + v2 + add;
            if (sum >= 10)
            {
                sum %= 10;
                add = 1;
            }
            else
            {
                add = 0;
            }

            tail->next = new ListNode{};
            tail->next->val = sum;
            tail = tail->next;

            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;

            if (l1 == nullptr && l2 == nullptr && add == 0)
                break;
        }

        return dummy.next;
    }
};
