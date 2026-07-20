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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* currL = l1;
        ListNode* currR = l2;

        ListNode* head = nullptr;
        ListNode* placeholder = head;

        bool carry = false;
        while (currL && currR) {
            int preCarrySum = currL->val + currR->val;
            if (carry) preCarrySum++;
            carry = false;
            if (preCarrySum >= 10) carry = true;
            int sum = preCarrySum % 10;
                        
            ListNode* newNode = new ListNode(sum);
            if (!head) {
                head = newNode;
                placeholder = newNode;
            } else {
                placeholder->next = newNode;
                placeholder = newNode;
            }
            
            currL = currL->next;
            currR = currR->next;
        }

        while (currL != nullptr) {
            int preCarrySum = currL->val;
            if (carry) preCarrySum++;
            carry = false;
            if (preCarrySum >= 10) carry = true;
            int sum = preCarrySum % 10;
                        
            ListNode* newNode = new ListNode(sum);
            if (!head) {
                head = newNode;
                placeholder = newNode;
            } else {
                placeholder->next = newNode;
                placeholder = newNode;
            }
            currL = currL->next;
        }

        while (currR != nullptr) {
            int preCarrySum = currR->val;
            if (carry) preCarrySum++;
            carry = false;
            if (preCarrySum >= 10) carry = true;
            int sum = preCarrySum % 10;
                        
            ListNode* newNode = new ListNode(sum);
            if (!head) {
                head = newNode;
                placeholder = newNode;
            } else {
                placeholder->next = newNode;
                placeholder = newNode;
            }
            currR = currR->next;
        }

        if (carry) {
            ListNode* newNode = new ListNode(1);
            placeholder->next = newNode;
            placeholder = newNode;
        }

        return head;
    }
};
