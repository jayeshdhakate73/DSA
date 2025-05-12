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
    // ListNode* Reverse(ListNode* &prev, ListNode* &curr){
    //     //base case
    //     if(curr==NULL){
    //         //LL reverse ho chuki hai 
    //         //reversed list ke head pe prev point kr rha hai 
    //         return prev;
    //     }
    //     //1 case hum solve krenge baki recurssion
    //     ListNode* forward = curr->next;
    //     curr->next=prev;
    //     //pointer kp 1 step aage kiya aur recurssion ko baki ka kaam krne padka deya
    //     prev=curr;
    //     curr=forward;
    //     //baki recurssion sambhal lega 
    //     return Reverse(prev, curr);
    // }

    ListNode* reverseList(ListNode* head) {

        ListNode* prev=NULL;
        ListNode* curr=head;
        

        while(curr!=NULL){
            ListNode* forward = curr->next;
            //forward pointer set ho gya 
            curr->next=prev;
            prev = curr;
            curr = forward;
        }

        //new head of LL is prev pointer
        return prev;

        
        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // ListNode* newHead = Reverse(prev, curr);
        // return newHead;
        
    }
};