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
        std::unordered_map<Node*, int> sourceNodes;
        std::unordered_map<int, Node*> newNodes;

        Node* cur = head;
        Node* prev = nullptr;
        Node* newHead = nullptr;
        int idx = 0;
        while(cur)
        {
            Node* node = new Node{cur->val};
            newNodes[idx] = node;
            sourceNodes[cur] = idx;
            ++idx;

            if (!newHead)
                newHead = node;

            if (prev)
                prev->next = node;

            prev = node;
            cur = cur->next;
        }

        cur = newHead;
        idx = 0;
        while(head)
        {
            Node* random = head->random;
            head = head->next;
            if (!random)
            {
                cur->random = nullptr;
                cur = cur->next;
                continue;
            }

            int sourceIdx = sourceNodes[random];
            cur->random = newNodes[sourceIdx];
            cur = cur->next;
        }

        return newHead;
    }
};
