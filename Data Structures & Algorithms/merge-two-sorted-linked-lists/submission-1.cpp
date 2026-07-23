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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = merge(list1->next, list2); 
            return list1;
        } else {
            list2->next = merge(list1, list2->next);
            return list2;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* node = merge(list1, list2);
        return node;
    }
};
