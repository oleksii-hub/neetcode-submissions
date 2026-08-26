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
        std::unordered_map<Node*, Node*> sourceToNewNodes;

        Node* cur = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;
        while(cur)
        {
            Node* node = new Node{cur->val};
            sourceToNewNodes[cur] = node;

            if (!newHead)
                newHead = node;

            if (prev)
                prev->next = node;

            prev = node;
            cur = cur->next;
        }

        cur = newHead;
        while(head)
        {
            Node* random = head->random;
            head = head->next;
            cur->random = sourceToNewNodes[random];
            cur = cur->next;
        }

        return newHead;
    }
};
