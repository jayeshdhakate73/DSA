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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *ans = head->next;
        ListNode *prev = NULL;

        while(head != NULL && head->next != NULL){
            ListNode *temp = head->next;
            if(prev != NULL) prev->next = temp;
            head->next = temp->next;
            temp->next = head;
            prev = head;
            head = head->next;
        }


        return ans;
    }
};