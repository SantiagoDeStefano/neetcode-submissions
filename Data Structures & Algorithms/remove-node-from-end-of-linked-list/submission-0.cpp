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
        ListNode *result = new ListNode(0, head);
        ListNode *current = result;
        for(int i = 0; i < n; i++) {
            head = head->next;
        }
        while(head != nullptr) {
            head = head->next;
            current = current->next;
        }
        current->next = current->next->next;
        return result->next;
    }
};
