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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
    return n == 1 ? nullptr : head;
}

        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        int jump = count-n;
        ListNode* temp1=head;
        for(int i=0; i<jump; i++){
            temp1=temp1->next;

        }
        ListNode* temp2=head;
        for(int i=0; i<jump-1; i++){
            temp2=temp2->next;

        }
        temp2->next=temp1->next;
        temp1->next=NULL;
        return head;


    }
};