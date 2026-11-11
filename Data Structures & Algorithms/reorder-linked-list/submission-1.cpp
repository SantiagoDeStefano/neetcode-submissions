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
    stack<ListNode*> stack;
    ListNode *current = head;
    ListNode *result = new ListNode();
    while(current != nullptr) {
        stack.push(current);
        current = current->next;
    }
    current = head;
    int size = stack.size();
    for(int i = 0; i < size/2; i++) {
        ListNode *temp = current->next;
        current->next = stack.top();
        stack.top()->next = temp;
        stack.pop();
        current = temp;
    }
    current->next = nullptr;
}
};
