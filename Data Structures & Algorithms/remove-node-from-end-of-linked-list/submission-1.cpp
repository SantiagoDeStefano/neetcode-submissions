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
    ListNode* dummy = new ListNode(0, head);
    ListNode* current = dummy;
    ListNode* step = dummy;
    for(int i = 0; i < n; i++) {
        step = step->next;
    }
    while(step->next != nullptr) {
        current = current->next;
        step = step->next;
    }
    current->next = current->next->next;
    return dummy->next;
}
};
