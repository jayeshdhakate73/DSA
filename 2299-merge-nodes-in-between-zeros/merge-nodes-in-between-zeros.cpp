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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next; // skip the first 0
        ListNode* dummy = new ListNode(0); // dummy head for result list
        ListNode* tail = dummy; // pointer to build the new list
        
        int sum = 0;

        while (temp != nullptr) {
            if (temp->val == 0) {
                // end of a segment
                ListNode* newNode = new ListNode(sum);
                tail->next = newNode;
                tail = tail->next;
                sum = 0; // reset sum for next segment
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
