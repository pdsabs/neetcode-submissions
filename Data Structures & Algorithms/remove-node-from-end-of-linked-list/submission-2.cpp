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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* findEnd = head;
        ListNode* findNode = head;
        ListNode* findPrev = head;

        for (int i = 1; i < n; i++) {
            findEnd = findEnd->next;
        }
        
        while (findEnd->next != nullptr) {
            findEnd = findEnd->next;
            findPrev = findNode;
            findNode = findNode->next;
        }

        findPrev->next = findNode->next;

        if (findNode == head) {
            head = findNode->next;
        }
        return head;
    }
};
