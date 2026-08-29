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
        stack<ListNode*> myStack;
        ListNode *current = head;
        while(current != nullptr) {
            myStack.push(current);
            current = current->next;
        }
        int size = myStack.size();

        current = head;
        for(int i = 0; i < size/2; i++) {
            myStack.top()->next = current->next;
            current->next = myStack.top();
            current = current->next->next;
            myStack.pop();
        }
        current->next = nullptr;
    }
};
