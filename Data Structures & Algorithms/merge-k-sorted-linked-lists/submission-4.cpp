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
ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *result = new ListNode(0);
    ListNode *current = result;
    auto compare = [](ListNode* a, ListNode* b) {
        return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

    for(int i = 0; i < lists.size(); i++) {
        ListNode *temp = lists[i];
        if(temp != nullptr) {
            minHeap.push(temp);
        }
    }

    while(!minHeap.empty()) {
        ListNode *node = minHeap.top();
        minHeap.pop();
        current->next = new ListNode(node->val);
        current = current->next;

        if(node->next != nullptr) {
            minHeap.push(node->next);
        }
    }
    return result->next;
}
};
