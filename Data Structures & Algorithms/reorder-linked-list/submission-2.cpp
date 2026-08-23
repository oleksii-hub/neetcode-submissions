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
    void reorderList(ListNode* head) {
        ListNode* list1 = head;
        ListNode* list2 = head;
        while (list2 && list2->next)
        {
            list1 = list1->next;
            list2 = list2->next->next;
        }
        list2 = list1->next;
        list1->next = nullptr;
        list1 = head;

        ListNode* prev = nullptr;
        while (list2)
        {
            ListNode* next = list2->next;
            list2->next = prev;
            prev = list2;
            list2 = next;
        }
        list2 = prev;

        ListNode dummy{};
        ListNode* tail = &dummy;
        while (list1 && list2)
        {
            ListNode* n1 = list1->next;
            ListNode* n2 = list2->next;
            tail->next = list1;
            tail->next->next = list2;
            list1 = n1;
            list2 = n2;
            tail = tail->next->next;
        }

        tail->next = list1;
        head = dummy.next;
    }
};
