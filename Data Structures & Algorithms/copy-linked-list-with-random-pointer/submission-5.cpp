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
        std::unordered_map<Node*, Node*> clone;
        clone.reserve(100);

        Node dummy{0};
        Node* tail = &dummy;

        for (Node* cur = head; cur; cur = cur->next) {
            tail->next = new Node{cur->val};
            clone[cur] = tail->next;
            tail = tail->next;
        }

        for (Node* cur = head; cur; cur = cur->next) {
            if (cur->random) {
                clone[cur]->random = clone.at(cur->random);
            }
        }

        return dummy.next;
    }
};
