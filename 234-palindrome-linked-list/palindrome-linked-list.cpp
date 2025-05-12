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
    ListNode* getMiddle(ListNode* &head, ListNode* &middleNodeKaPrev) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
                middleNodeKaPrev = slow;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* Reverse(ListNode* &prev, ListNode* &curr) {
        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        if (head->next == NULL) return true;

        // Get middle node and the node before it
        ListNode* firstHalfHead = head;
        ListNode* middleNodeKaPrev = NULL;
        ListNode* middleNode = getMiddle(head, middleNodeKaPrev);

        // Break the list into two halves
        if (middleNodeKaPrev != NULL) {
            middleNodeKaPrev->next = NULL;
        } else {
            // For 2-node case, break at head
            head = NULL;
        }

        // Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = middleNode;
        ListNode* secondHalfHead = Reverse(prev, curr);

        // Compare both halves
        ListNode* temphead1 = firstHalfHead;
        ListNode* temphead2 = secondHalfHead;
        while (temphead1 != NULL) {
            if (temphead1->val != temphead2->val) {
                return false;
            }
            temphead1 = temphead1->next;
            temphead2 = temphead2->next;
        }

        return true;
    }
};
