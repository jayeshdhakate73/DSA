class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Create dummy nodes for two partitions
        ListNode* lessHead = new ListNode(0);
        ListNode* lessTail = lessHead;
        
        ListNode* greaterHead = new ListNode(0);
        ListNode* greaterTail = greaterHead;
        
        ListNode* curr = head;
        while (curr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }
        
        // Terminate the greater list and connect lists
        greaterTail->next = nullptr;
        lessTail->next = greaterHead->next;
        
        return lessHead->next;
    }
};