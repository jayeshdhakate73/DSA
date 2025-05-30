class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        
        // Step 1: Get the total length of the list
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }

        // Step 2: If the node to delete is the head itself
        if (n == len) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3: Move to the (len - n - 1)th node
        int pos = len - n;
        ListNode* temp1 = head;
        for (int i = 1; i < pos; i++) {
            temp1 = temp1->next;
        }

        // Step 4: Delete the nth node from end
        ListNode* forward = temp1->next;
        temp1->next = forward->next;
        delete forward;

        return head;
    }
};
