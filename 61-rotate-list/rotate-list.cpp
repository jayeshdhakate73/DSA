class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Count the length
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        // Step 2: Calculate effective rotations
        k = k % len;
        if (k == 0) return head;

        // Step 3: Find new tail (at position len - k)
        int stepsToNewTail = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set new head and break the list
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;

        return newHead;
    }
};
