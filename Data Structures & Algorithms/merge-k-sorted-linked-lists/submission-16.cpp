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

    ListNode* mergeKLists(const std::vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        std::vector listsCopy = lists;
        while (listsCopy.size() > 1) {
            std::vector<ListNode*> merged;
            const auto size = listsCopy.size();
            merged.reserve((size + 1) / 2);

            for (std::size_t i = 0; i < size; i += 2) {
                if (i + 1 < size) {
                    merged.push_back(mergeTwoSortedLists(listsCopy[i], listsCopy[i + 1]));
                } else {
                    merged.push_back(listsCopy[i]);
                }
            }

            listsCopy = std::move(merged);
        }

        return listsCopy[0];
    }
};
