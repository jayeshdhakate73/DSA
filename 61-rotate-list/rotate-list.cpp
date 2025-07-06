class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Count length
        ListNode* temp = head;
        int len = 1;
        while (temp->next != nullptr) {
            temp = temp->next;
            len++;
        }

        // Step 2: Make the list circular
        temp->next = head;

        // Step 3: Find the breaking point
        k = k % len;
        int jump = len - k;

        ListNode* temp1 = head;
        for (int i = 1; i < jump; i++) {
            temp1 = temp1->next;
        }

        // Step 4: Break the circle
        ListNode* temp2 = temp1->next;
        temp1->next = NULL;

        return temp2;
    }
};
