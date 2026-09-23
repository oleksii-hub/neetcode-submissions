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
    ListNode* at(ListNode* node, int k)
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
        ListNode* prevTail = &dummy;

        while(true)
        {
            ListNode* kth = at(prevTail, k); // 3
            if (!kth)
                break;

            ListNode* nextHead = kth->next; // 4
            ListNode* curHead = prevTail->next; // 1

            ListNode* prev = nextHead;
            ListNode* cur = curHead;
            while(cur != nextHead)
            {
                ListNode* next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }

            prevTail->next = kth; // 3
            prevTail = curHead; // 1
        }

        return dummy.next;
    }
};
