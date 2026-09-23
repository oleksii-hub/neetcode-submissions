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
    static ListNode* kthFrom(ListNode* node, int k)
    {
        while(node && k > 0)
        {
            node = node->next;
            --k;
        }

        return node;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy{0, head};
        ListNode* groupPrev = &dummy;

        while (ListNode* kth = kthFrom(groupPrev, k))
        {
            ListNode* nextGroupHead = kth->next;
            ListNode* groupStart = groupPrev->next;

            ListNode* prev = nextGroupHead;
            ListNode* cur = groupStart;
            while(cur != nextGroupHead)
            {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            groupPrev->next = kth;
            groupPrev = groupStart;
        }

        return dummy.next;
    }
};
