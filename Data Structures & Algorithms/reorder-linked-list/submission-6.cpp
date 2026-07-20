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
        ListNode* counter = head;
        int n = 0;
        while (counter != nullptr) {
            counter = counter->next;
            n++;
        }

        int nodes_from_end = n / 2;
        stack<ListNode*> endNodes;

        ListNode* curr = head;
        ListNode* temp;
        int nodes_from_start = n - nodes_from_end;
        while (nodes_from_start > 0) {
            if (nodes_from_start == 1) {
                temp = curr;
            }
            curr = curr->next;
            temp->next = nullptr;
            nodes_from_start--;
        }

        while (curr != nullptr) {
            endNodes.push(curr);
            curr = curr->next;
        }

        curr = head;
        while (!endNodes.empty()) {
            ListNode* temp = curr->next;
            curr->next = endNodes.top();
            endNodes.pop();
            curr->next->next = temp;
            curr = temp;
        }
    }
};
