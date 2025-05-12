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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL){
            //fast ko 1 step aage kro
            fast = fast->next;
            //check kro ki fast null hai kya 1 step ke baad
            if(fast!=NULL){
                fast=fast->next;
                //ab fast ke 2 steps complete ho gye 
                //ab slow ko bhi 1 step aage badhao 
                slow = slow->next;
            }
        }
        return slow;
        
    }
};