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
    ListNode* mergeTwoSortedLists(ListNode* list1, ListNode* list2) {
        ListNode dummy{};
        ListNode* tail = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;

        return dummy.next;
    }

    ListNode* mergeKLists(std::vector<ListNode*> lists) {
        if (lists.empty()) { return nullptr; }

        std::size_t n = lists.size();
        while (n > 1) {
            std::size_t out = 0;
            for (std::size_t i = 0; i < n; i += 2) {
                lists[out++] = (i + 1 < n)
                    ? mergeTwoSortedLists(lists[i], lists[i + 1])
                    : lists[i];
            }
            n = out;
        }

        return lists[0];
    }
};
