/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) { return nullptr; }

        // 1. weave: A -> A' -> B -> B' -> ...
        for (Node* cur = head; cur; cur = cur->next->next) {
            Node* copy = new Node{cur->val};
            copy->next = cur->next;
            cur->next = copy;
        }

        // 2. wire randoms: the clone of X is always X->next
        for (Node* cur = head; cur; cur = cur->next->next) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
        }

        // 3. unweave, restoring the original
        Node dummy{0};
        Node* tail = &dummy;
        for (Node* cur = head; cur; cur = cur->next) {
            tail->next = cur->next;
            tail = tail->next;
            cur->next = tail->next;
        }

        return dummy.next;
    }
};